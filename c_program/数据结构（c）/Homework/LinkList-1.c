#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;   // 设置元素类型为整型

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LinkList;

int main(){
    LinkList L = (LinkList)malloc(sizeof(struct LinkNode));
    L->next = L;    // 初始化
    // 读入数据
    ElemType e;
    LinkList p = L,q;
    FILE *fp = fopen("LinkList-1","r");
    fscanf(fp,"%d%*c",&(L->data));
    while(~fscanf(fp,"%d%*c",&e)){ 
        q = (LinkList)malloc(sizeof(struct LinkNode));
        q->data = e;
        q->next = p->next;
        p->next = q;
        p = p->next;
    }// while
    ElemType x; // 待删除数据
    puts("请输入待删除结点元素: ");
    scanf("%d",&x);
    // 查表
    p = L;
    do{
        if(p->data == x){
            q = L;
            while(q->next!=p)   // 查表，找待删除节点的前驱
                q = q->next;
            q->next = p->next;
            if(p == L){
                L = q->next;
            }
            p->next = NULL;
            free(p);
            p = q->next;
        }
        else
            p = p->next;
    }while(p->next!=L);

    // 输出表
    p = L;
    do{
        if(p->next==p)
            break;  // 空
        printf("%d ",p->data);
        p = p->next;
    }while(p!=L);
}