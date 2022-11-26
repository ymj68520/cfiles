// BinaryTree
// 1. 二叉树第 i 层最多有2^(i-1)个节点
// 2. 深度为k的二叉树最多有2^k - 1 个节点
// 3. 对任意的二叉树T，如果终端节点数为n0 度为2的结点数为n2 则有 n0 = n2 + 1
// 完全二叉树
// 4. 具有n个节点的二叉树的深度为 floor(log2(n))+1
// 5. (1) 节点i的parent为 floor(i/2)
// 5. (2) 若2*i>n,则节点无leftchild否则leftchild是2*i
// 5. (3) 若2*i+1>n,则节点无rightchild 否则 是 2*i+1
// 节点i所处的层数为 floor(log2(i+1))+1 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100   // 最大节点数

// 顺序存储就是以数组的形式存储，根节点为[0]或者[1]，但是这个只适用于完全二叉树，一般的
// 二叉树会造成内存浪费。因此使用链式结构，即链表。
#ifndef ET
#define TElemType int
#endif
typedef struct BiTNode{
    TElemType data; // 节点的值
    struct BiTNode *lchile,*rchild; // 左右孩子指针
}BiTNode,*BiTree;

#define Status bool
#define OK true
#define ERROR false
#ifndef Nil
#define Nil 0               // 定义TElemType的空
#endif
#define ClearBiTree DestroyBiTree  // 清空与销毁操作一样

void Visit(TElemType T){
    printf("%d",T);
}

// 构造空二叉树
void InitBiTree(BiTree T){
    T = NULL;
}
// 若二叉树存在，则销毁二叉树
void DestroyBiTree(BiTree T){
    if(T){  // 非空树
        DestroyBiTree(T->lchile);   // 递归
        DestroyBiTree(T->rchild);
        free(T);    // 删除根节点
        T = NULL;   // 空指针赋0
    }
}
// 若二叉树存在，则对节点执行操作Visit() 
// 先序递归遍历T，对每个节点调用Visit一次且仅一次
void PreOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    if(T){  // T非空
        Visit(T->data);                     // 先访问根节点
        PreOrderTraverse(T->lchile,Visit);  // 遍历左子树
        PreOrderTraverse(T->rchild,Visit);  // 遍历右子树        
    }
}
// 中序递归遍历T，对每个节点调用Visit 一次仅且一次
void InOrderTraverse(BiTree T, void(*Visit)(TElemType)){
    if(T){  // T非空
        PreOrderTraverse(T->lchile,Visit);
        Visit(T->data);
        PreOrderTraverse(T->rchild,Visit);
    }
}
// 后序递归遍历T，对每个节点调用Visit 一次仅且一次
void LastOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    if(T){  // T非空
        PreOrderTraverse(T->lchile,Visit);
        PreOrderTraverse(T->rchild,Visit);
        Visit(T->data);
    }
}
// 判断二叉树是否为空
Status BiTreeEmpty(BiTree T){
    if(T)
        return false;
    else
        return true;
}
// 返回二叉树的深度
int BiTreeDepth(BiTree T){
    int i,j;
    if(!T)
        return 0;   // 空树深度为0
    i = BiTreeDepth(T->lchile);
    j = BiTreeDepth(T->rchild);
    return i>j?i+1:j+1;
}
#ifndef Nil
// 返回二叉树的根
TElemType Root(BiTree T){
    if(BiTreeEmpty(T))
        return Nil;
    else    // 树非空
        return T->data;
}
#endif
// 返回指针p指向的节点的值
TElemType Value(BiTree p){
    return p->data;
}
// 给p所指节点赋值为value
void Assign(BiTree p,TElemType value){
    p->data = value;
}






typedef BiTree QElemType;   // 定义队列元素为二叉树的指针类型
#include "../queue/queue.h"
#ifndef Nil
// 返回二叉树T中指向元素s的结点的指针
BiTree Point(BiTree T,TElemType s){
    LinkQueue q;
    QElemType a;
    if(T){  // 树非空
        InitQueue(&q);   // 初始化队列
        EnQueue(&q,T);   // 根指针入队
        while(!QueueEmpty(q))   // 队非空
        {
            DeQueue(&q,&a);     // 出队，队列元素赋值给a
            if(a->data == s){   // a所指节点的值为s
                DestroyQueue(&q);   // 销毁队列
                return a;
            }
            if(a->lchile)   // 有leftchild
                EnQueue(&q,a->lchile);  // 入队
            if(a->rchild)
                EnQueue(&q,a->rchild);
        }
        DestroyQueue(&q);   // 销毁队列
    }
    return NULL;    // 二叉树中没有元素为s的结点
}

// 返回e的leftchild
TElemType LeftChild(BiTree T, TElemType e){
    BiTree a;
    if(T){  // T非空
        a = Point(T,e);     // a是指向节点e的指针
        if(a && a->lchile)  // T中存在节点e且e有leftchild
            return a->lchile->data;
    }
    return Nil;
}
TElemType RightChild(BiTree T,TElemType e){
    BiTree a;
    if(T){
        a = Point(T,e);
        if(a && a->rchild)
            return a->rchild->data;
    }
    return Nil;
}
#endif
// 二叉树T存在，且p指向T中某个节点，LR为0或1
// 根据LR的值，删除T中p所指节点的左子树或右子树
Status DeleteChild(BiTree p, int LR){
    if(p){      // 非空
        if(LR == 0){    // 删除左子树
            ClearBiTree(p->lchile);
        }
        else if(LR == 1)
            ClearBiTree(p->rchild);
        return OK;
    }
    return ERROR;
}
// 若二叉树T存在，Visit是对节点的相应操作函数
// 层序递归遍历T(利用队列), 对每个节点调用Visit一次仅且一次
void LeveOrderTraverse(BiTree T,void(*Visit)(TElemType)){
    LinkQueue q;
    QElemType a;
    if(T){
        InitQueue(&q);   // 初始化队列
        EnQueue(&q,T);   // 根指针入队
        while(!QueueEmpty(q)){  // 队列不空
            DeQueue(&q,&a);     // 出队元素（指针），赋给a
            Visit(a->data);
            if(a->lchile)
                EnQueue(&q,a->lchile);
            if(a->rchild)
                EnQueue(&q,a->rchild);
        }
        printf("\n");
        DestroyQueue(&q);
    }
}
// 按先序次序输入二叉树节点的值
void CreatBiTree(BiTree *T){
    TElemType ch;
    scanf("%d",&ch);
    if(ch == NULL){
        T = NULL;
    }
    else    // 节点非空
    {
        *T = (BiTree)malloc(sizeof(BiTNode));    // 生成根节点
        if(!(*T))
            exit(EXIT_FAILURE);
        (*T)->data = ch;
        
        CreatBiTree(&(*T)->lchile);

        CreatBiTree(&(*T)->rchild);
    }
}
// 二叉树T存在，e是T中某个节点
// 若e是T的非根节点，则返回他的parent否则返回“空”
TElemType Parent(BiTree T,TElemType e){
    LinkQueue q;
    QElemType a;
    if(T){  // 非空
        InitQueue(&q);
        EnQueue(&q,T);
        while(!QueueEmpty(q)){
            DeQueue(&q,&a);
            if(a->lchile && a->lchile->data == e ||
                a->rchild && a->rchild->data == e)
                    return a->data;
            else{   // 未找到
                if(a->lchile)
                    EnQueue(&q,a->lchile);
                if(a->rchild)
                    EnQueue(&q,a->rchild);
            }
        }
    }
    return Nil;
}
// 二叉树T存在，e是某个节点
// 返回e的leftsibling。若e是T的leftchild或无leftchild，则返回空
TElemType LeftSibling(BiTree T,TElemType e){
    TElemType a;
    BiTree p;
    if(T){
        a = Parent(T,e);
        if(a!=Nil){
            p = Point(T,e);
            if(p->lchile && p->rchild && p->rchild->data==e)    // 存在且右是e
                return p->lchile->data;         // 返回p的leftchild（e的左兄弟）
        }
    }
    return Nil;
}
// 返回e的rightsibling
TElemType RightSibling(BiTree T,TElemType e){
    TElemType a;
    BiTree p;
    if(T){
        a = Parent(T,e);
        if(a!=Nil){
            p = Point(T,a);
            if(p->lchile && p->rchild &&p->lchile->data == e)
                return p->rchild->data;
        }
    }
    return Nil;
}
// 二叉树T存在，p指向T中某个节点，LR为0或1，非空二叉树c与T不相交且右子树为空
// 根据LR为0或1，插入c为T中p所指节点的左子树或右子树。即p点所指节点的原有左右子树
// 成为c的右子树
Status InsertChild(BiTree p,int LR,BiTree c){
    if(p){
        if(LR == 0){    // 把二叉树c插为p所指的左子树
            c->rchild = p->rchild;  // p所指节点的原有左子树成为c的右子树
            c->lchile = c;  // 二叉树c成为p的左子树
        }
        else{
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return OK;
    }
    return ERROR;       // p空

}





// 定义栈元素为二叉树的指针类型
typedef BiTree SElemType;
#include "../Stack/stack.h"

// 采用二叉链表存储结构，Visit是对元素操作的函数
// 中序遍历二叉树T的非递归算法（利用栈），对每个元素调用VIsit
void InOrderTraverse2(BiTree T,void(*Visit)(TElemType)){
    SqStack S;
    BiTree p;
    InitStack(&S);
    Push(&S,T);         // T进栈，无论空否
    while(!StackEmpty(S)){      // 栈不空
        while(GetTop(S,&p)&&p)  // 栈顶元素不空
            Push(&S,p->lchile); // 向左走到尽头，入栈leftchild
        Pop(&S,&p);         // 空指针退栈，退掉最后入栈的空指针
        if(!StackEmpty(S)){ // 访问节点，向右一步
            Pop(&S,&p);     // 弹出栈顶元素（非空）
            Visit(p->data); // 访问刚弹出的结点的数据
            Push(&S,p->rchild); // 入栈rightchild
        }
    }
    printf("\n");
    DestroyStack(&S);    // 销毁栈
}
