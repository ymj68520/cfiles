// 串的块链存储

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define OVERFLOW 2
#define Status bool
#define OK true
#define ERROR false
#define FASLSE false
#define TRUE true

#define DestroyString ClearString // DestroyString()与ClearString()作用相同

#define CHUNK_SIZE 4 // 可由用户定义的块大小

typedef struct Chunk{
    char ch[CHUNK_SIZE];
    struct Chunk *next;
}Chunk;
typedef struct LString{
    Chunk *head,*tail; // 串的头和尾指针
    int curlen; // 串的当前长度
}LString;
//“ # ”作为填补空余的字符，不计为串的字符.
#define blank '#'
// 初始化(产生空串)字符串T。
void InitString(LString * T){
    T->curlen = 0;
    T->head = T->tail = NULL;
}
// 生成一个其值等于chars的串T(要求chars中不包含填补空余的字符)。
//成功返回OK；否则返回ERROR
Status StrAssign(LString *T, char *chars){
    /*
    int i,j,k,m;
    Chunk *p,*q;
    i = strlen(chars);  //i为chars的长度.
    if(!i || strchr(chars,blank))   //chars长度为0或者chars中包含补空字符
        return ERROR;
    T->curlen = i;
    j = i/CHUNK_SIZE;   //节点数
    if(i%CHUNK_SIZE)    //最后存不满的部分
        j++;
    for(k=0;k<j;k++){
        p = (Chunk* )malloc(sizeof(Chunk));
        if(!p)      //生成失败
            return ERROR;
        for(m=0;m<CHUNK_SIZE && *chars;m++)     //给块节点赋值
            *(p->ch+m) = *(chars++);        
        if(k==0)        //第一个链块
            T->head = p = q; //头指针指向第一个节点
        else{
            q->next = p;
            q = p;
        }
        if(!*chars){
        // 最后一个链块
            T->tail = q;
            q ->next = NULL;
            for(;m<CHUNK_SIZE;m++)
                *(q->ch+m) = blank;
        }
    }
    return OK;
    */
    int i=0,j,k,m;
    Chunk *p,*q;
    i = (int )strlen(chars);
    if(!i||strchr(chars,blank)) // 串长为0或chars中包含填补空余的字符
        return ERROR;
    T->curlen=i;
    j=i/CHUNK_SIZE; // j为块链的结点数
    if(i%CHUNK_SIZE)
        j++;
    for(k=0;k<j;k++)
    {
        p=(Chunk*)malloc(sizeof(Chunk)); // 生成块结点
        if(!p) // 生成块结点失败
            return ERROR;
        for(m=0;m<CHUNK_SIZE&&*chars;m++) // 给块结点的数据域赋值
            *(p->ch+m)=*chars++;
        if(k==0) // 第一个链块
        T->head=q=p; // 头指针指向第一个链块
        else
        {
            q->next=p;
            q=p;
        }
        if(!*chars) // 最后一个链块
        {
            T->tail=q;
            q->next=NULL;
            for(;m<CHUNK_SIZE;m++) // 用填补空余的字符填满链表
            *(q->ch+m)=blank;
        }       
    }
    return OK;
}
// 将串T的内容转换为字符串， chars为其头指针。成功返回OK；否则返回ERROR。另加换行符
Status ToChars(LString T,char * chars){
    Chunk *p = T.head;  //p指向头节点
    char *q;
    chars = (char*)malloc((T.curlen+1) * sizeof(char));
    if(!chars || !T.curlen){    //分配失败，或者串长为零
        return ERROR;
    }
    q = chars;  //q指向chars的第一个字符
    int i;
    while(p){   //块链没有结束
        for(i=0;i<CHUNK_SIZE;++i)
            if(p->ch[i]!=blank)     // 当前字符不是补空字符
                *q++ = (p->ch[i]);  // 赋给q所指字符空间
        p=p->next;
    }
    chars[T.curlen]=0; // 串结束符
    return OK;
}
// 初始条件：串S存在
// 操作结果：由串S复制得串T，去掉填补空余的字符。成功返回OK；否则返回ERROR
Status StrCopy(LString * T,LString S){
    char * c;           //存储S的指针
    if(!ToChars(S,c))   //转换为字符串，地址赋给c
        return ERROR;
    Status i;           //状态变量
    i = StrAssign(T,c); //初始化一个值为c的LString
    free(c);            //释放c
    return i;           //返回状态
}
// 初始条件：串S存在。操作结果：若S为空串，则返回TRUE；否则返回FALSE
Status StrEmpty(LString S){
    if(S.curlen)
        return FASLSE;
    else 
        return TRUE;
}
// 若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare(LString S,LString T){
    char *t1,*t2;       //存储S，T的内容
    ToChars(S,t1);      //转换
    ToChars(T,t2);
    int i;
    int j=0;            // 状态值
    for(i=0;i<S.curlen&&i<T.curlen;i++)
        if(t1[i]!=t2[i]){
            j = t1[i]-t2[i];
            free(t1);   // 必须释放内存
            free(t2);
            return j;
        }
        free(t1);       // 释放
        free(t2);
    return j;
}
// 返回S的元素个数，称为串的长度
int StrLength(LString S){
    return S.curlen;
}
// 初始条件：串S存在。操作结果：将S清为空串
void ClearString(LString * S){
    Chunk *p,*q;        // 链指针
    p = S->head;        // 令p指向头
    while(p){
        q = p->next;    // q为中介
        free(p);        // 依次释放p
        p = q;
    }   // 全部释放完后，块链为空
    S->head = S->tail = NULL;   //头尾为空
    S->curlen = 0;      // 长度为0
}
// 用T返回由S1和S2联接而成的新串(中间可能有填补空余的字符)
Status Concat(LString * T,LString S1,LString S2){
    LString *a1,*a2;      // 临时串a1,a2
    InitString(a1);    
    InitString(a2);
    int i,j;            // 状态值,是否copy成功
    i = StrCopy(a1,S1); // StrCopy 清除补空字符
    j = StrCopy(a2,S2); // a1,a2中没有补空字符，不排除结尾的补空字符 打印时跳过补空就OK
    if(!i || !j)        // 至少有一个没有copy成功
        return ERROR;
    T->curlen = S1.curlen+S2.curlen;
    T->head = a1->head; //直接链接
    a1->tail->next = a2->head;  //链接
    T->tail = a2->tail;
    return OK;
}      
// 用Sub返回串S的第pos个字符起长度为len的子串。
// 其中， 1≤pos≤StrLength(S)且0≤len≤StrLength(S)-pos+1
Status SubString(LString *Sub, LString S,int pos,int len){
    /*
    char *a,*b;         // 转换为字符串容易操作
    if(pos<1 || pos>StrLength(S) || len<0 || len>StrLength(S)-pos+1)
        return ERROR;       // pos 或 len 值非法
    if(!ToChars(S,a))   // 转换失败
        return ERROR;
    b = (char*)malloc(len*sizeof(char));
    int i;
    for(i=0;i<len;++i)
        b[i] = a[pos+i-1];
    Status j = FASLSE;      //状态值
    StrAssign(Sub,b);       // 生成串
    free(a);                // 释放内存
    free(b);
    return j;
    */
    char *b,*c;
    Status i;
    if(pos<1||pos>S.curlen||len<0||len>S.curlen-pos+1) // pos或len值不合法
        return ERROR;
    if(!ToChars(S,c)) // c为串S的内容
        return ERROR;
    b=c+pos-1; // b指向串c中串Sub内容的首地址
    b[len]=0; // Sub结束处赋0(字符串结束符)
    i=StrAssign(Sub,b); // 将串b的内容赋给Sub
    free(c);
    return i;
}
// T为非空串。若主串S中第pos个字符之后存在与T相等的子串，
// 则返回第一个这样的子串在S中的位置，否则返回0
int Index(LString S,LString T,int pos){
    char *a,*t;     // 临时串
    int i,n,m;
    LString sub;
    if(pos>0 && pos<StrLength(S)){  // pos值合法
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while(i<=n-m+1){
            SubString(&sub,S,i,m);  // sub为从S的第i个字符起，长度为m的子串
            if(StrCompare(sub,T))   // sub不等于T
                ++i;
            else
                return i;
        }
    }
    return 0;    
}
// 1≤pos≤StrLength(S)+1。在串S的第pos个字符之前插入串T
Status StrInsert(LString *S, int pos,LString T){
    if(pos<1 || pos>StrLength(*S)+1)    // pos 值不合法
        return ERROR;
    char *a,*b; // 临时串
    int i=0,n=0;    // 长度
    int j;      // 计数器
    Status k;
    if(!ToChars(*S,a))  // 转换失败
        return ERROR;
    if(!ToChars(T,b))
        return ERROR;
    // sizt_t == unsigned long
    while(a[i]!='\0')
        i++;
    while(b[n]!='\0')
        n++;
    a = (char*)realloc(a,(i+n+1)*sizeof(char)); // 增加空间
    for(j=i;j>=pos-1;--j)   // 后移
        a[j+n] = a[i];
    for(j=0;j<n;++j)
        a[j+pos-1] = b[j];
    InitString(S);          // 释放S的原有空间，生成新块
    k = StrAssign(S,a);
    free(a);                // 释放内存
    free(b);
    return k;
}
// 从串S中删除第pos个字符起长度为len的子串
Status StrDelete(LString *S,int pos,int len){
    char *c;
    int i;
    Status k;
    if(pos<1 || pos>(S->curlen)-len+1||len<0) // pos， len的值超出范围
    return ERROR;
    if(!ToChars(*S,c)) // c为串S的内容
    return ERROR;
    int j=0;
    while(c[j]!='\0')
        j++;
    for(i=pos+len-1;i<=j;i++){
        c[i-len]=c[i]; // c为删除后串S的内容
    }
    InitString(S); // 释放S的原有存储空间
    k=StrAssign(S,c); // 由c生成新的串S
    free(c);
    return k;
}
// 初始条件：串S， T和V存在， T是非空串
// 操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串
// 此函数与串的存储结构无关
Status Replace(LString *S,LString T,LString V){
    int i=1; // 从串S的第一个字符起查找串T
    if(StrEmpty(T)) // T是空串
        return ERROR;
    do{
        i=Index(*S,T,i); // 结果i为从上一个i之后找到的子串T的位置
        if(i) {// 串S中存在串T
            StrDelete(S,i,StrLength(T)); // 删除该串T
            StrInsert(S,i,V); // 在原串T的位置插入串V
            i+=StrLength(V); // 在插入的串V后面继续查找串T
        }
    }while(i);
    return OK;
}
// 输出字符串T。另加换行
void StrPrint(LString T){
    int i=0,j;
    Chunk *h;
    h=T.head;
    while(i<T.curlen){
        for(j=0;j<CHUNK_SIZE;j++){
            if(*(h->ch+j)!=blank) // 不是填补空余的字符
            {
                printf("%c",*(h->ch+j));
                ++i;
            }
        }
        h=h->next;
    }
    printf("\n");
}
