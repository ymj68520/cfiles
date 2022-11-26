#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}*LinkList;

LinkList reverselinklist(LinkList L){
    if(!L || !L->next)
        return L;
    LinkList p = L,q = NULL,r;
    while(p!=NULL){
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    return q;  
}
void PRINT(LinkList L){
    LinkList p = L;
    while(p){
        printf("%d,",p->data);
        p = p->next;
    }
    putchar('\n');
}
int main(){
    LinkList L = (LinkList)malloc(sizeof(struct LNode));
    LinkList p = L,q;
    int n;
    scanf("%d",&n);
    if(n){
        n--;
        scanf("%d",&L->data);
    }
    while(n--){
        q = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d",&q->data);
        p->next = q;
        p = p->next;
    }
    PRINT(L);
    L = reverselinklist(L);
    PRINT(L);
}