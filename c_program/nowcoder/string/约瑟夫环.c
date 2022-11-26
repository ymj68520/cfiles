#include <stdio.h>
#include <stdlib.h>

typedef struct people{
    int num;
    struct people *next;
}People;

int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    if(n==1)
        printf("%d",n-1);
    People *p,*q;
    People header;
    header.next = (People*)malloc(sizeof(People));
    p = header.next;
    p->num=0;
    for(int i=1;i<n;i++){
        q = (People *)malloc(sizeof(People));
        q->num = i;
        p->next = q;
        p = p->next;
    }
    q->next = header.next;
    p = header.next;
    while(p->num!=k){
        p = p->next;
    }
    while(p->next!=p){
        for(int j=1;j<m-1;j++){
            p = p->next;
        }
        People *r = p->next;
        p->next = r->next;
        p = p->next;
        free(r);      
    }
    printf("%d",p->num);
}