#define OVERFLOW -1
#define bool _Bool
#define true 1
#define false 0
#include <stdbool.h>

typedef struct Student{
    //序号
    int order; 
    //张（zhang）最多四字20字符
    char name[21]; 
    //学号
    int gra_number; 
    //true = 男  false = 女
    int sex;  
    //c
    double cgrade; 
    //数学
    double math;   
    //英语
    double eng;     
    //语文
    double chinese;      
    //此处均分移出结构体
    
    //总成绩
    double sum;

    //链表指针域
    struct Student *next;

}Student,ST,*Linklist;

typedef struct StuHeader{
    struct Student *head;
    struct Student *tail;
}

typedef long size_t;
extern void *malloc(size_t __size);
extern void exit(int _status);

void Listorder(Linklist L, int i);
char * ListDel(Linklist L, int i);
bool ListInsert(Linklist L, int i);
int locateElem(Linklist L, void * e, char ch, bool (*compare)(int E1, int E2));
bool GetElem(Linklist L, int i, void * e, char ch);
int ListLength(Linklist L);
bool Listempty(Linklist L);
void DestroyList(Linklist L);
void Clearlist(Linklist L);
Linklist initlist(Linklist L);

//建立空表
Linklist initlist(Linklist L){
    L = (Linklist)malloc(sizeof(ST)); //分配一个头结点的空间并使L指向它
    if(!L) //分配失败
        exit(OVERFLOW);
    L->next = L; //头结点指向尾结点
    
    return L;
}
//改变List 即清空 若L存在则将其清空，不存在则error
void Clearlist(Linklist L){
    Linklist p,q;
    L = L-> next; //L指向头结点
    p = L -> next; //p指向第一个节点
    while(p!=L){    //未到表尾
        q = p -> next;
        free(p);
        p = q;
    } 
    L -> next = L; //头结点指向自身

}
//销毁List
void DestroyList(Linklist L){
    Clearlist(L); //清空
    free(L);
    L = NULL;
}
//判断是否为空表
bool Listempty(Linklist L){
    if(L->next == L) //头结点指向自身
        return true;
    else 
        return false;
}
//查看data个数
int ListLength(Linklist L){
    int i = 0;
    Linklist p=L -> next; //p指向头结点
    while (p!=L){ //未到表尾
        i++;
        p = p->next; //指向下一个
    }
    return i;
}
//查找第i个元素并赋值返回，且返回状态 (待改)
bool GetElem(Linklist L, int i, void * e, char ch){
    int j = 1;
    Linklist p = L->next->next;
    if(i<=0 || i>ListLength(L)){ //如果i不存在
        return false;
    }
    while(j<i){
        j++;
        p = p->next;
    }
    /* ？？？？
    switch (ch)
    {
    case 'o':
        e = p->order;
        break;
    case 'n':
        e = p->name; //数组地址
        break;
    case 'g':
        e = p->gra_number;
        break;
    case 's':
        e = p->sex;
        break;
    case 'c':
        e = &(p->cgrade);
        break;
    case 'm':
        e = &(p->math);
        break;
    case 'e':
        e = &(p->eng);
        break;
    default:
        e = &(p->pe);
        break;
    }
    */
    return true;
}
//返回满足compare（）函数的元素位序 不存在返回0
int locateElem(Linklist L, void * e, char ch, bool (*compare)(int E1, int E2)){
    int i=0;
    Linklist p =L->next->next; //指向第一个节点
    while(p!=L->next){      //不指向头结点
        i++;
    /* 。。。？？？
        switch (ch)
    {
    case 'o':
        if(compare(p->order,e))
        return i;
        break;
    case 'n':
        if(compare(p->name,e)) //数组地址
        return i;
        break;
    case 'g':
        if(compare(e, p->gra_number))
        return i;
        break;
    case 's':
        if(compare(e, p->sex))
        return i;
        break;
    case 'c':
        if(compare(e, p->cgrade))
        return i;
        break;
    case 'm':
        if(compare(e, p->math))
        return i;
        break;
    case 'e':
        if(compare(e, p->eng))
        return i;
        break;
    default:
        if(compare(e,p->pe))
        return i;
        break;
    }//switch
    */
    p = p->next;
    }//while
}
//在第i个位置之前插入一个元素   //修改提示输入
bool ListInsert(Linklist L, int i){
    Linklist p = L->next,s;
    int j = 0;
    if(i<=0 || i>ListLength(L)+1) //i值不合法
        return false;
    while (j<i-i) //寻找i-1节点
    {
        j++;
        p = p->next;
    }
    s = (Linklist) malloc (sizeof(ST));
    //输入赋值 改
    //s ->order = e;
    s->next = p->next;
    p->next = s;

    if(p == L) //插在表尾
        L = s;
    return true;
}
//删除节点 是否需要返回其值？？ 暂定返回名字
char * ListDel(Linklist L, int i){
    Linklist q, p=L->next;
    int j=0;
    char * na;
    na =(char*) malloc(21*sizeof(char));
    if(i<=0 || i>ListLength(L))     //节点不存在
        return "error!";
    while(j<i-1){
        j++;
        p = p->next;
    }
    q = p->next; //q指向待删除节点
    p->next = q->next;
    Listorder(L,i);
    for(int k=0;k<=20 && q->name[k] !='\0'; k++)
        na[k] = q->name[k];
    if(L==q) //待删除表尾
        L = p;
    free(q);
    return na;
}
//调整序号
void Listorder(Linklist L, int i){   //指明待删除位置
    Linklist p = L->next;
    int j=0;
    while(j<i){
        j++;
        p = p->next;
    }
    for(--j;j<ListLength(L);j++){
        p->order--;
        p = p->next;
    }
    return;
}


