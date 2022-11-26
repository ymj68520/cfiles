// 不设头结点的单链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define Status  bool
#define OK  true
#define ERROR false
// Destroy 功能等同于 Clear
#define DestroyList ClearList
#ifndef elem    // 邻接表存储图时使用
typedef int ElemType;

typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}LNode;//*LinkList;
#endif
void InitList(LinkList * L){
    *L = NULL;
}
void ClearList(LinkList *L){
    LinkList p;
    while(L){
        p = *L;
        *L = (*L)->next;
        free(p); 
    }
}
Status ListEmpty(LinkList L){
    if(L)
        return false;
    else
        return true;
}
int ListLength(LinkList L){
    int i=0;
    LinkList p = L;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L,int i,ElemType *e){
    int j=1;
    LinkList p = L;
    if(i<1)
        return ERROR;
    while(j<i && p){
        j++;
        p = p->next;
    }
    if(j==i && p){
        *e = p->data;
        return OK;
    }
    return ERROR;
}
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
    int i=0;
    LinkList p = L;
    while(p){
        i++;
        if(compare(p->data,e))
            return i;
        p = p->next;
    }
    return 0;
}
Status ListInsert(LinkList *L,int i,ElemType e){
    int j=1;
    LinkList s,p = *L;
    if(i<1)
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    if(i==1){
        s->next = *L;
        *L = s;
    }    
    else{
        while(p && j<i-1){
            j++;
            p = p->next;
        }
        if(!p)
            return ERROR;
        s->next = p->next;
        p->next = s;
    }
    return OK;
}
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j=1;
    LinkList q,p=*L;
    if(!L)
        return ERROR;
    else if(i==1){
        (*L) = p->next;
        *e = p->data;
        free(p);
    }
    else{
        while(p->next && j<i-1){
            j++;
            p = p->next;
        }
        if(!p->next || j>i-1)
            return ERROR;
        q = p->next;
        p->next = q->next;
        *e = q->data;
        free(q);
    }
    return OK;
}
void ListTraverse(LinkList L,void(*vi)(ElemType)){
    LinkList p = L;
    while(p){
        vi(p->data);
        p = p->next;
    }
    putchar('\n');
}
/*
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e){
    LinkList q,p = L;
    while(p->next){
        q = p->next;
        if(q->data == cur_e){
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return ERROR;
}
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e){
    LinkList p = L;
    while(p->next){
        if(p->data == cur_e){
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}
*/
LinkList Point(LinkList L,ElemType e,Status(*eaqual)(ElemType,ElemType),LinkList *p){
   // 查找表L中与e满足eaqual（）条件的结点，如果找到，返回指向该节点的指针 p指向该节点的前驱
   // 若该节点是表的首元素 则 p=NULL，如表L中无满足条件的结点则返回NULL p未定义
    int j,i = LocateElem(L,e,eaqual);
    if(i){   // 找到
        if(i==1)    // 是首结点
        {
            p = NULL;
            return L;
        }
        *p = L;
        for(j=0;j<i;j++)    // p所指节点的前驱
            *p = (*p)->next;
        return (*p)->next;
    }
    return NULL;
}



