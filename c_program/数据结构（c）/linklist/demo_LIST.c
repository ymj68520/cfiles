#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

bool compare (int i, int j);

int main() {
    Linklist l;
    l = initlist(l);
    l->data = 10;
    printf("%p\n",l);
    l->next->next->data = 11;
    printf("%p\n",l);
    Clearlist(l);
    if(Listempty(l))
     puts("true");
    else
     puts("false");
    int f = 1;
    l->data = f;
    Linklist p = l->next;
    int i=0;
    Linklist q;
    while(i<3){
        q = (Linklist) malloc (sizeof(nt));
        q->next = l;
        p ->next = q;
        p = p->next;
        scanf("%d",&(q->data));
        i++;
    }
    printf("表长为：%d\n",ListLength(l));
    int e = 1;
    GetElem(l,1,&e);
    printf("查找的元素为：%d\n",e);
    printf("与e相同的为第：%d 个元素\n",locateElem(l,&e,(*compare)));
    p = l->next;
    ListInsert(l,3);
    ListInsert(l,1);
    ListDel(l,1);
    ListDel(l,1);
    ListDel(l,3);
    while(p != l){
        printf("%d ",p->data);
        p = p->next;
    }
    


    
    return 0;
}
bool compare (int i,int j){
    if(i==j)    return true;
    else    return false;
}