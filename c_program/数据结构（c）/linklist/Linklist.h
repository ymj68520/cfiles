#include <stdbool.h>
#ifndef elem
typedef int ElemType;
#endif
#define OVERFLOW -1

#ifndef bool
#define bool _Bool
#endif

#ifndef true
#define true 1
#define false 0
#endif

#ifndef NULL
#define NULL ((LinkList)0)
#endif

struct notelink{
    ElemType data;
    struct notelink *next;
};

typedef struct notelink LNode;
typedef struct notelink * LinkList;
/*
typedef unsigned long size_t;
extern void *malloc(size_t __size);
extern void free(void *__ptr);
extern void exit(int _status);
*/
bool ListDel(LinkList L, int i, ElemType *e);
bool ListInsert(LinkList L, int i, ElemType e);
int locateElem(LinkList L, int * e, bool (*compare)(int E1, int E2));
bool GetElem(LinkList L, int i, int * e);
int ListLength(LinkList L);
bool Listempty(LinkList L);
void DestroyList(LinkList L);
void Clearlist(LinkList L);
LinkList InitList(LinkList L);

//建立空表，循环表，尾结点为头指针
LinkList InitList(LinkList L){  //返回指针使malloc分配的内存被准确指向
    L=(LinkList)malloc(sizeof(LNode)); // 产生头结点，并使L指向此头结点
    if(!L) // 存储分配失败
    exit(OVERFLOW);
    L->next=L; // 指针域指向头结点
    return L;
}
//改变List 即清空 若L存在则将其清空，不存在则error
void Clearlist(LinkList L){ //循环链表
    LinkList p,q;
    L=L->next; // L指向头结点
    p=L->next; // p指向第一个结点
    while(p!=L) // 没到表尾
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=L; // 头结点指针域指向自身
}
//销毁List
void DestroyList(LinkList L){
    LinkList q,p=L->next; // p指向头结点
    while(p!=L) // 没到表尾
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(L);
    L=NULL;
}
//判断是否为空表,头结点指向头指针
bool Listempty(LinkList L){
    if(L->next==L) // 空
        return true;
    else
        return false;
}
//查看data个数
int ListLength(LinkList L){
    int i=0;
    LinkList p=L->next; // p指向头结点
    while(p!=L) // 没到表尾
    {
        i++;
        p=p->next;
    }
    return i;
}
//查找第i个元素并赋值返回，且返回状态 
bool GetElem(LinkList L, int i, ElemType * e){
    int j=1; // 初始化， j为计数器
    LinkList p=L->next->next; // p指向第一个结点
    if(i<=0||i>ListLength(L)) // 第i个元素不存在
        return false;
    while(j<i)
    { // 顺指针向后查找，直到p指向第i个元素
        p=p->next;
        j++;
    }
    *e=p->data; // 取第i个元素
    return true;
}
//返回满足compare（）函数的元素位序 不存在返回0
int locateElem(LinkList L, ElemType * e, bool (*compare)(ElemType E1, ElemType E2)){
    int i=0;
    LinkList p=L->next->next; // p指向第一个结点
    while(p!=L->next)
    {
        i++;
        if(compare(p->data,*e)) // 满足关系
            return i;
        p=p->next;
    }
    return 0;
}
bool PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
{ // 初始条件：线性表L已存在
// 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱；
// 否则操作失败， pre_e无定义
    LinkList q,p=L->next->next; // p指向第一个结点
    q=p->next;
    while(q!=L->next) // p没到表尾
    {
        if(q->data==cur_e)
        {
            *pre_e=p->data;
            return true;
        }
    p=q;
    q=q->next;
    }
    return false; // 操作失败
}
bool NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
{ // 初始条件：线性表L已存在
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继；
// 否则操作失败， next_e无定义
LinkList p=L->next->next; // p指向第一个结点
while(p!=L) // p没到表尾
{
if(p->data==cur_e)
{
*next_e=p->next->data;
return true;
}
p=p->next;
}
return false; // 操作失败
}
//在第i个位置之前插入一个元素   
bool ListInsert(LinkList L, int i, ElemType e){
    LinkList p=L->next,s; // p指向头结点
    int j=0;
    if(i<=0||i>ListLength(L)+1) // 无法在第i个元素之前插入
        return false;
    while(j<i-1) // 寻找第i-1个结点
    {
        p=p->next;
        j++;
    }
    s=(LinkList)malloc(sizeof(LNode)); // 生成新结点
    s->data=e; // 插入L中
    s->next=p->next;
    p->next=s;
    if(p==L) // 改变尾结点
    L=s;
    return true;
}
//删除节点 是否需要返回其值？？
bool ListDel(LinkList L, int i,ElemType *e){
    LinkList p=L->next,q; // p指向头结点
    int j=0;
    if(i<=0||i>ListLength(L)) // 第i个元素不存在
        return false;
    while(j<i-1) // 寻找第i-1个结点
    {
        p=p->next;
        j++;
    }
    q=p->next; // q指向待删除结点
    p->next=q->next;
    *e=q->data;
    if(L==q) // 删除的是表尾元素
        L=p;
    free(q); // 释放待删除结点
    return true;
}


