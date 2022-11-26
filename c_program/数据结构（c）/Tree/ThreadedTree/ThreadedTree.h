// 后序 中序遍历时访问节点的顺序决定前驱后继
// 增加两个指针域 forward backward 分别指向前驱与后继
// 或 增加两个指示点（Tag）0表示指向下一个树，1表示前驱
// 在一次遍历中完成前驱后继的寻找

#include <stdio.h>
#include <stdbool.h>

typedef int TElemType;
typedef enum PointerTag {Link,Thread};  // Link=0：指针， Thread=1：线索
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag,RTag;               //左右标志
}BiThrNode,*BiThrTree;

// 方便起见 设定一个头结点 类似于链表
// 其rchild域指向中序遍历时访问的最后一个节点
// 反之，二叉树中序遍历的第一个节点的lchild域指针和最后一个节点的rchild指向头结点
// 类似建立一个双向线索链表

typedef bool Status;

Status InOrderTraverse_Thr(BiThrTree T,Status(*Visit)(TElemType)){
    // T指向头结点 头结点的左链lchild指向根节点
    // 中序遍历二叉线索树T的非递归算法，对每个元素调用函数Visit
    BiThrTree p;
    p = T->lchild;          // p指向根节点
    while(p!=T){            // 空树或遍历结束
        while(p->LTag==Link)
            p = p->lchild;
        if(!Visit(p->data)) // 访问左子树为空的结点
            return false;
        while(p->RTag==Thread && p->rchild!=T){
            p = p->rchild;
            Visit(p->data); // 访问后继结点
        }
        p = p->rchild;
    }
    return true;
}

// 线索化二叉树
// 将二叉树中的空指针改为指向前驱或后继的线索
// 而前驱后继的信息只有在遍历中动态存在
// 即线索化的过程是在遍历的过程中修改空指针的过程
// 为记下遍历过程中访问的先后顺序 附设一个指针pre始终指向当前访问节点的上一个访问节点
// 即 若p指向当前访问节点 pre指向p的前驱
#include <stdlib.h>
void InThreading(BiThrTree p,BiThrTree pre){
    if(p){
        InThreading(p->lchild,pre);     // 左子树线索化
        if(!p->lchild){
            p->LTag = Thread;
            p->lchild = pre;        // 前驱线索
        }
        if(!pre->rchild){
            pre->RTag = Thread;
            pre->rchild = p;
        }        // 后继线索
        pre = p;        // 保持pre指向p的前驱
        InThreading(p->rchild,pre);     // 右子树线索化
    }
}
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T){
    // 中序遍历二叉树T,并将其中序线索化，Thrt指向头指针
    BiThrTree pre;
    if(!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(EXIT_FAILURE);
    (*Thrt)->LTag = Link;(*Thrt)->RTag = Thread;    // 建立头结点
    (*Thrt)->rchild = (*Thrt);                      // 右指针回指
    if(!T)            // 如果二叉树空，则左指针回指
        (*Thrt)->lchild = (*Thrt);
    else {
        (*Thrt)->lchild = T;
        pre = *Thrt;
        InThreading(T,pre);             // 中序遍历线索化
        pre->rchild = (*Thrt);          // 最后一个
        pre->RTag = Thread;             // 节点线索化
        (*Thrt)->rchild = pre;          
    }
    return true;
}