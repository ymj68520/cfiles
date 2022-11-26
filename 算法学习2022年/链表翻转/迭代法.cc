#include <iostream>
using namespace std;
typedef struct node{
    int data;
    node * next;
}*linknode;

void Linknode_inverse(linknode head){
    linknode pre,ne,cur;
    pre = NULL;
    cur = head;
    while(cur!=NULL){
        ne = cur->next;
        cur->next = pre;
        pre = cur;
        cur = ne;
    }
}

int main(){
    node h,n1,n2,n3,n4,n5;
    h.data = 0; h.next = &n1;
    n1.data = 1; n1.next = &n2;
    n2.data = 2; n2.next = &n3;
    n3.data = 3; n3.next = &n4;
    n4.data = 4; n4.next = &n5;
    n5.data = 5;
    Linknode_inverse(&h);
    linknode p = &h;
    while(p!=NULL){
        printf("%d, ",p->data);
        p = p->next;
    }

    return 0;
}