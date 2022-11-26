#include <stdio.h>
#include <stdlib.h>
typedef struct source{
    int n;
    struct source *next;
}Source;

int main (){
    int n;
    while(scanf("%d",&n)!=EOF){
        int int_n[n];
        Source header,*p,*q;
        p = &header;
        for(int i=0;i<n;i++){
            q = (Source*)malloc(sizeof(Source));
            scanf("%d",&(q->n));
            p->next = q;
            p = p->next;
        }
        int del;
        scanf("%d",&del);
        p = &header;
        while(p->next!=NULL && p->next->n!=del){
            p = p->next;
        }
        if(p->next==NULL){
            if(p->n==del){
                q = p->next;
                p->next = q->next;
                free(q);
            }
        }
        else if(p->next->n==del){
            q = p->next;
            p->next = q->next;
            free(q);
        }
        p = header.next;
        while(p->next!=NULL){
            printf("%d ",p->n);
            p = p->next;
        }
        printf("%d\n",p->n);
    }
    return 0;
}