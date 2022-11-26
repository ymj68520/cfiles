// 树的存储结构
#include <stdio.h>
#include <stdlib.h>
#ifndef tety
typedef char TElemType;  // 节点类型 调用该头文件的程序文件定义
#endif
#define Nil '#'
// 1.双亲表示法
// 这种结构利用了每个节点只有一个parent的特点（根除外）
// PARENT(T,X)操作可以在常数时间内实现
// ROOT(T)反复调用PARENT操作知道遇见无parent的结点，便是根
// 但是在求child节点时需要遍历整个结构 
#define MAX_TREE_SIZE 100
typedef struct PTNode{  // 节点结构
    TElemType data;
    int parent;     // 双亲位置域
}PTNode;
typedef struct{ // 数结构
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;    // 根的位置 节点数
}PTree;

// 2.孩子表示法
// 将每个节点的孩子节点排列起来，看成一个线性表 且以单链表作存储结构
// 则n个节点有n个孩子链表（叶子节点的孩子链表为空表）
// 而n个头指针又组成一个线性表
// 为了便于查找，可以使用顺序存储结构
// 孩子表示法便于那些涉及孩子的操作的实现 而不适用于parent操作
typedef struct CTNode{  // 孩子节点
    int child;          // 孩子节点在数组中的位置    
    struct CTNode *next;// 线性表
}*ChildPtr;
typedef struct{
    TElemType data;
    ChildPtr firstchild;    // 孩子链表头指针
}CTBox;
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;            // 根位置 节点数
}CTree;

// 此外，孩子表示法可以与双亲表示法结合起来使用

// 二叉链表——孩子兄弟存储法
// 一棵树无论有多少分叉，它最多有一个长子和一个排序在其下的兄弟
// 如此则每个节点的结构就统一到了二叉链表结构，这样有利于对节点进行操作
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstchild,*nextsibling; 
}CSNode,*CSTree;
#define ClearTree DestroyTree
void InitTree(CSTree *T){   // 构造空树
    *T = NULL;
}
void DestroyTree(CSTree *T){
    if(T){
        DestroyTree(&((*T)->firstchild));
        DestroyTree(&((*T)->nextsibling));
        free(*T);
        *T = NULL;
    }
}
typedef CSTree QElemType;

#include <string.h>
#include "../../queue/queue.h"  // 链队列

void CreateTree(CSTree *T){
    char c[20];     // 临时存放孩子节点（假设不超过20个）的值
    CSTree p,p1;
    LinkQueue q;
    int i,m;
    InitQueue(&q);  // 初始化队列
    printf("请输入根节点（字符型，#为空）：");
    c[0] = Nil;     
    scanf("%c%*C",&c[0]);
    if(c[0]!=Nil){  // 非空树
        (*T) = (CSTree)malloc(sizeof(CSNode));  // 建立根节点
        (*T)->data = c[0];  // 赋值
        (*T)->nextsibling = NULL;   // 根节点无兄弟
        EnQueue(&q,*T);     // 入队根节点的指针
        while(!QueueEmpty(q)){
            DeQueue(&q,&p);     // 出队一个节点的指针
            printf("请按长幼输入节点%c的所有孩子：",p->data);
            gets(c);
            m = strlen(c);
            if(m>0) // 有孩子
            {
                p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));// 长子节点
                p1->data = c[0];    // 给长子节点赋值
                EnQueue(&q,p1);     // 入队长子
                for(i=1;i<m;++i){   // 对于除了长子之外的其他孩子
                    p1->nextsibling = (CSTree)malloc(sizeof(CSNode));// 兄弟节点
                    p1 = p1->nextsibling;
                    p1->data = c[i];
                    EnQueue(&q,p1);
                }
                p1->nextsibling = NULL; // 最后一个节点无兄弟
            }
            else    // 无孩子
                p->firstchild = NULL;   // 长子指针为空
        }
    }
    else
        (*T) = NULL;    // 空树
}
// 若树存在，判断树是否为空 若空返回true
Status TreeEmpty(CSTree T){
    
    if(T)
        return false;
    else
        return true;
}
// 若树存在，返回树的深度
int TreeDepth(CSTree T){
    CSTree p;
    int depth,max=0;
    if(!T)
        return 0;
    for(p = T->firstchild;p;p = p->nextsibling){// 对于T的所有孩子节点（由p指向）
        depth = TreeDepth(p);   // 递归求深度
        if(depth>max)
            max = depth;
    }
    return max+1;
}
// 返回p所指节点的值
TElemType Value(CSTree p){
    return p->data;
}
// 返回T的根
TElemType Root(CSTree T){
    if(T)
        return Value(T);
    else
        return Nil;
}
// 返回二叉链表树T中值为s的结点的指针
CSTree Point(CSTree T,TElemType s){
    LinkQueue q;
    QElemType a;
    if(T){
        InitQueue(&q);
        EnQueue(&q,T);
        while(QueueEmpty(q)){
            DeQueue(&q,&a);
            if(a->data==s)
                return a;
            if(a->firstchild)
                EnQueue(&q,a->firstchild);
            if(a->nextsibling)
                EnQueue(&q,a->nextsibling);
        }
    }
    return NULL;
}
// 将树T中值为cur_e的结点值改为value
Status Assign(CSTree *T,TElemType cur_e,TElemType value){
    CSTree p;
    if(T){
        p = Point(*T,cur_e);
        if(p){
            p->data = value;
            return true;
        }
    }
    return false;
}
// 返回树T中值为cur_e的双亲节点
TElemType Parent(CSTree T,TElemType cur_e){
    CSTree p,t;
    LinkQueue q;
    InitQueue(&q);
    if(T){
        if(Value(T)==cur_e)
            return Nil;
        EnQueue(&q,T);
        while(!QueueEmpty(q)){
            DeQueue(&q,&p);
            if(p->firstchild){
                if(p->firstchild->data==cur_e)
                    return Value(p);
                t = p;
                p = p->firstchild;
                EnQueue(&q,p);
                while(p->nextsibling){
                    p = p->nextsibling;
                    if(Value(p)==cur_e)
                        return Value(t);
                    EnQueue(&q,p);
                }
            }
        }
    }
    return Nil;     // 树空或没找到
}
// 返回树T中节点值为cur_e的最左孩子，节点非叶子
TElemType LeftChild(CSTree T,TElemType cur_e){
    CSTree f;
    f = Point(T,cur_e);
    if(f && f->firstchild)
        return f->firstchild->data;
    else
        return Nil;
}
// 树T中若cur_e存在右兄弟，则返回
TElemType RightSibling(CSTree T,TElemType cur_e){
    CSTree f;
    f = Point(T,cur_e);
    if(f&&f->nextsibling)
        return f->nextsibling->data;
    else
        return Nil;
}
// 树T存在，p指向T中某个节点，1<=i<=(p所指节点的度)+1，非空树c与T不相交
// 插入c为T中p节点的第i棵子树，因为p所指节点的地址不会改变，故p不需要传入指针
Status InsertChild(CSTree *T,CSTree p,int i,CSTree c){
    int j;
    CSTree q;
    if(T){
        if(i==1){
            // 插入为长子   p的原长子现在是c的下一个兄弟（c本无兄弟）
            c->nextsibling = p->firstchild;
            // p的长子指针指向c（c成为长子）
            p->firstchild = c;
        }
        else{
            // c不是长子
            // q指向p的长子节点
            q = p->firstchild;
            j=2;
            while(q && j<i){    // 找c的插入点，并由q指向
                q = q->nextsibling; // q指向下一个兄弟节点
                j++;    // 计数+1
            }
            if(j==i){   // 找到插入位
                // c的下一个兄弟指向p的原第i个孩子
                c->nextsibling = q->nextsibling;
                q->nextsibling = c; // 在p中插入c作为p的第i个孩子
            }
            else    // p原有孩子树小于i-1
                return false;
        }
        return true;
    }
    else
        return false;   // T 空
}
// 树T存在，p指向T中某个节点，1<=i<=p所指节点的度
// 删除p所指节点的第i课子树
// 因为p所指节点的地址不会改变，故不需传入指针
Status DeleteChild(CSTree *T,CSTree p,int i){
    CSTree b,q;
    int j;
    if(T){
        if(i==1){   // 删除长子
            // 将长子分离
            b = p->firstchild;  // b指向p的长子节点
            p->firstchild = b->nextsibling; // p的原次子为现在的长子
            // p的长子节点成为待删除子树的根节点，其下一个兄弟为空
            b->nextsibling = NULL;
            DestroyTree(&b);    // 销毁由b指向的p的长子节点树
        }
        else{   // 删除非长子节点
            q = p->firstchild;  // q指向p的长子节点
            j = 2;
            while(q && j<i){
                // 寻找第i棵树
                q = q->nextsibling;     // q指向下一个兄弟
                j++;
            }
            if(j==i){
                b = q->nextsibling; // b指向待删除子树
                q->nextsibling = b->nextsibling;    // 从树T中移出这棵子树
                b->nextsibling = NULL;  // 待删除子树的根节点的下一个兄弟为空
                DestroyTree(&b);
            }
            else    // p原有孩子数小于i
                return false;
        }
        return true;
    }
    else
        return false;
}
// 后根遍历孩子——兄弟二叉链表结构的数T
void PostOrderTraverse(CSTree T,void(*Visit)(TElemType)){
    CSTree p;
    if(T){
        if(T->firstchild){
            PostOrderTraverse(T->firstchild,Visit); // 后根遍历长子树
            p = T->firstchild->nextsibling; // p指向长子的下一个兄弟
            while(p){
                PostOrderTraverse(p,Visit);
                p = p->nextsibling;
            }
        }
        Visit(Value(T));    // 最后访问根节点
    }
}
// 层序遍历孩子——兄弟二叉链表
void LevelOrderTraverse(CSTree T,void(*Visit)(TElemType)){
    CSTree p;
    LinkQueue q;
    InitQueue(&q);
    if(T){
        Visit(Value(T));
        EnQueue(&q,T);
        while(!QueueEmpty(q)){
            DeQueue(&q,&p);
            if(p->firstchild){
                p = p->firstchild;
                Visit(Value(p));
                EnQueue(&q,p);
                while(p->nextsibling){
                    p = p->nextsibling;
                    Visit(Value(p));
                    EnQueue(&q,p);
                }
            }
        }
    }
    printf("\n");
}
// 先序遍历二叉链表
void PreOrderTraverse(CSTree T,void(*Visit)(TElemType)){
    if(T){
        Visit(T->data); // 先访问节点
        PreOrderTraverse(T->firstchild,Visit);
        PreOrderTraverse(T->nextsibling,Visit);
    }
}
