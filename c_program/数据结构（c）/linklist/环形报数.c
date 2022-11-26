typedef int ElemType;
#include <stdbool.h>
#include <stdio.h>
#include "Linklist.h"

int main(){
    LinkList baoshu;
    baoshu = InitList(baoshu);
    int i;    // 计数器（序号）
    int n=3; // 总人数
    LinkList p=baoshu->next,q;
    for(i=1;i<=n;i++){
        p->data = i;
        q = (LinkList)malloc(sizeof(LNode));
        q->next = baoshu;
        p->next = q;
        p = p->next;
    }// 初始化链表
    baoshu->data = ListLength(baoshu);
    LinkList m;
    int j=0;
    m = baoshu->next;
    i=1;
    while(baoshu->data != 1){
        j++;
        if(i>n)
            i-=n;
        if(j==3){
            int e;
            ListDel(baoshu,i,&e);
            baoshu->data=ListLength(baoshu);
        }
        m = m->next;
        if(p=baoshu)
            m = m->next;
        i++;
    }
    int em = baoshu->next->data;
    printf("%d\n",em);
    return 0;
}