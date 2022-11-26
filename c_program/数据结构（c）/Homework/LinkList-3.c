#include <stdio.h>
#include <stdlib.h>

typedef int ELemType;

typedef struct LNode{
    ELemType data;
    struct LNode *next;
    struct LNode *prior;
}LNode,*LinkList;


int main(){
    FILE *fp = fopen("LinkList-1","r");
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = L->prior = L;
    ELemType e;
    fscanf(fp,"%d%*c",&e);
    L->data = e;
    LinkList q,p = L;
    while(~fscanf(fp,"%d%*c",&e)){
        q = (LinkList)malloc(sizeof(LNode));
        q->data = e;
        L->prior = q;   // 表位表头
        q->next = L;
        p->next = q;
        q->prior = p;
        p = p->next;
    }
    printf("%d ",L->data);
    for(p = L->next;p!=L;p=p->next)
        printf("%d ",p->data);
    putchar('\n');
    // Inorder 
    if(L && (L)->next!=(L)->prior){
        ELemType temp;
        p = (L)->prior;
        q = (L);
        while(p!=q && p->prior != q->next){
            temp = q->data;     // 交换
            q->data = p->data;
            p->data = temp;
            p = p->prior;   // 移位
            q = q->next;
        }
    }
    printf("%d ",L->data);
    for(p = L->next;p!=L;p=p->next)
        printf("%d ",p->data);
}