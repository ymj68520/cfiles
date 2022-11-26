//堆分配存储表示
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

typedef struct {
    char * ch;
    int length;
}HString;
#define DestroyString ClearString // DestroyString()与ClearString()作用相同
// 初始条件：串S存在。操作结果：由串S复制得串T
void StrAssign (HString *T, char *chars){
    int i,j;
    if(T->ch)
        free(T->ch);
    i=strlen(chars);
    if(!i){ //chars 长度为0
        T->ch = NULL;
        T->length = 0;
    }
    else{   //chars 长度不为0
        T->ch = (char*)malloc(i*sizeof(char)); //分配串空间
        if(!T->ch)  //分配失败
            exit(OVERFLOW);
        for(j=0;j<i;++j){
            T->ch[j] = chars[j];
        }
        T->length = i;
    }
}
// 初始条件：串S存在。操作结果：由串S复制得串T
void StrCpy(HString *T,HString S){
    int n;
    if(T->ch)
        free(T->ch);
    n = strlen(S.ch);
    T->ch = (char *)malloc(n*sizeof(char));
    if(!T->ch)
        exit(OVERFLOW);
    for(int i=0;i<n;++i){
        T->ch[i] = S.ch[i];
    }
    T->length = S.length;
}
// 初始条件：串S存在。操作结果：若S为空串，则返回TRUE；否则返回FALSE
Status StrEmpty(HString S){
    if(S.length==0 && S.ch == NULL)
        return TRUE;
    else
        return FASLSE;
}
// 若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare(HString T,HString S){
    int i;
    for(i=0;i<T.length&&i<S.length;++i){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return T.length-S.length;
}
// 返回S的元素个数，称为串的长度
int StrLength(HString S){
    return S.length;
}
// 将S清为空串
void ClearString(HString * S){
    free(S->ch);
    S->ch = NULL;
    S->length = 0;
}
// 用T返回由S1和S2联接而成的新串
void Concat(HString *T,HString S1,HString S2){
    if(T->ch)
        free(T->ch); // 释放旧空间
    int len1 = strlen(S1.ch);
    int len2 = strlen(S2.ch);
    T->length = len1 + len2;
    T->ch = (char*)malloc(T->length*sizeof(char));
    if(!T->ch)
        exit(OVERFLOW); //分配失败
    //字符串拷贝
    for(int i=0;i<len1;++i)
        T->ch[i] = S1.ch[i];
    for(int i=0;i<len2;++i)
        T->ch[i+len1] = S2.ch[i];
}
// 用Sub返回串S的第pos个字符起长度为len的子串。
// 其中,1≤pos≤StrLength(S)且0≤len≤StrLength(S)-pos+1
Status SubString(HString * sub, HString S, int pos,int len){
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return ERROR;
    if(sub->ch)
        free(sub->ch); //释放旧空间
    if(!len){
        //空子串
        sub->ch = NULL;
        sub->length = 0;
    }
    else{
        //完整子串
        sub->ch = (char*)malloc(len*sizeof(char));
        if(!sub->ch)
            exit(OVERFLOW);
        for(int i=0;i<=len-1;i++){
            sub->ch[i] = S.ch[pos+i-1];
        }
        sub->length = len;
    }

    return OK;
}
// 初始化(产生空串)字符串T。
void InitString(HString *T){
    T->length=0;
    T->ch=NULL;
}
// T为非空串。若主串S中第pos个字符之后存在与T相等的子串，
// 则返回第一个这样的子串在S中的位置；否则返回0
int Index(HString S,HString T,int pos){
    int n,m,i;
    HString sub;
    InitString(&sub);
    if(pos>0){
        n=StrLength(S);
        m=StrLength(T);
        i=pos;
        while(i<=n-m+1){
            SubString(&sub,S,i,m);
            if(StrCompare(sub,T)!=0)
                ++i;
            else
                return i;
        }
    }
    return 0;
}
// 1≤pos≤StrLength(S)+1。在串S的第pos个字符之前插入串T
Status StrInsert(HString * S,int pos,HString T){
    if(pos<1||pos>S->length+1) // pos不合法
        return ERROR;
    if(T.ch){   //T非空
        S->ch = (char*)realloc(S->ch,(S->length+T.length)*sizeof(char));
        if(!S->ch)  //分配失败
            return ERROR;
        //串长len-1为最后一个数组元素的位置，从0开始
        for(int i=S->length-1;i>=pos-1;--i){    //后移，腾出空间
            S->ch[i+T.length] = S->ch[i];
        }
        for(int i=0;i<T.length;++i)     //拷贝串
            S->ch[pos-1+i] = T.ch[i];
        S->length+=T.length;

        return OK;
    }
    return ERROR;   //T空
}
// 从串S中删除第pos个字符起长度为len的子串
Status StrDelete (HString * S,int pos,int len){
    if(S->length<pos+len-1) //数组越界
        return ERROR;
    for(int i=pos-1;i<S->length-len;i++)
        S->ch[i] = S->ch[i+len];
    S->length-=len;
    S->ch = (char*)realloc(S->ch,S->length*sizeof(char));
    return OK;
}
// 初始条件：串S， T和V存在， T是非空串
// 操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串
// 此函数与串的存储结构无关
Status Replace(HString *S,HString T,HString V){
    int i=1;    //从第一个值开始查找串
    if(StrEmpty(T))
        return ERROR;
    do{
        i = Index(*S,T,i);
        if(i){      //存在这样的T
            StrDelete(S,i,StrLength(T));    //删除该串
            StrInsert(S,i,V);       //插入V
            i+=StrLength(V);        //在其之后继续查找
        }
    }while(i);
    return OK;
}
// 输出T字符串。加上换行。
void StrPrint(HString T){
    for(int i=0;i<T.length;++i)
        printf("%c",T.ch[i]);
    printf("\n");
}
