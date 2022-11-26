#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node,*ptrNode,*List;

#define true 1
#define false 0

int JudgeTwoListCrossed(List L1,List L2);
int main () {
    List L1,L2;
    return 0;
}

int JudgeTwoListCrossed(List L1,List L2){
    List q = L1->next;
    if(L1==NULL || L2 == NULL)
        return false;
    if(L1 == NULL && L2==NULL)
        return true;
    while(q!=NULL){
        List p = L2->next;
        while(p!=NULL){
            if(q == p)  //节点地址相同，值不同？？// 没有值，垃圾数据
                return true;
            p = p->next;
        }
        q = q->next;
    }

    return false;
}