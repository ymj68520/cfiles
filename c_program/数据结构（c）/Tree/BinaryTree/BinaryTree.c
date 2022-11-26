
//#define CHAR 1      // 字符型
#define CHAR 0    // 整型

#include "BinaryTree.h"

void main(){
    int i;
    BiTree T,p,c;
    TElemType e1,e2;
    InitBiTree(T);
    printf("构造二叉树后，树空否？%d(1：是 0：否). 树的深度 = %d.\n",
        BiTreeEmpty(T),BiTreeDepth(T));
    e1 = Root(T);
    if(e1 != Nil)
        printf("二叉树的根为：%d",e1);
    else
        printf("树空，无根");
    # if CHAR
        printf("请按先序输入二叉树（如：ab###表示a为根节点，b为左子树的二叉树：\n");
    # else
        printf("请按先序输入二叉树（如：1 2 0 0 0表示1为根节点，2为左子树的二叉树：\n");
    # endif
    CreatBiTree(&T);
    printf("建立二叉树后，数空否？%d(1：是 0：否). 树的深度 = %d.\n",
        BiTreeEmpty(T),BiTreeDepth(T));
    e1 = Root(T);
    if(e1 != Nil)
        printf("二叉树的根为：%d",e1);
    else
        printf("树空，无根");
    printf("中序递归遍历二叉树：\n");
    InOrderTraverse(T,Visit);
    printf("后序递归遍历二叉树：\n");
    LastOrderTraverse(T,Visit);
    printf("请输入一个节点的值：");
    scanf("%d",&e2);
    p=Point(T,e2);
    Assign(p,e2);
    printf("层序遍历二叉树:\n");
    LeveOrderTraverse(T,Visit);
    e1 = Parent(T,e2);
    if(e1 != Nil)
        printf("%d的parent是：%d",e2,e1);
    else
        printf("%d没有parent。",e2);
    e1 = RightChild(T,e2);
    if(e1 != Nil)
        printf("%d的RightChild是：%d",e2,e1);
    else
        printf("%d没有RightChild。",e2);
    e1 = LeftChild(T,e2);
    if(e1 != Nil)
        printf("%d的LeftChild是：%d",e2,e1);
    else
        printf("%d没有LeftChild。",e2);
    e1 = LeftSibling(T,e2);
    if(e1 != Nil)
        printf("%d的LeftSibling是：%d",e2,e1);
    else
        printf("%d没有LeftSibling。",e2);
    e1 = RightSibling(T,e2);
    if(e1 != Nil)
        printf("%d的RightSibling是：%d",e2,e1);
    else
        printf("%d没有RightSibling。",e2);
    
    InitBiTree(c);
    printf("请构造一个右子树为空的二叉树：\n");
    # if CHAR
        printf("请按先序输入二叉树（如：ab###表示a为根节点，b为左子树的二叉树：\n");
    # else
        printf("请按先序输入二叉树（如：1 2 0 0 0表示1为根节点，2为左子树的二叉树：\n");
    # endif
    CreatBiTree(&c);
    printf("中序遍历二叉树c :\n");
    InOrderTraverse(c,Visit);
    printf("\n树c插入到树T中，请输入树T中树C的双亲节点 c为左（0）右（1）子树：");
    scanf("%d %d",&e1,&i);
    p = Point(T,e1);
    InsertChild(p,i,c);
    // 将树c插入到二叉树T中作为节点e1（p所指）的左（i=0）或右（i=1）的子树
    printf("先序递归遍历二叉树:\n");
    PreOrderTraverse(T,Visit);
    printf("\n删除子树，请输入待删除子树的双亲节点 左(0)或右(1)子树:");
    p = Point(T,e1);
    DeleteChild(p,i);
    printf("先序递归遍历二叉树:\n");
    PreOrderTraverse(T,Visit);
    printf("中序递归遍历二叉树:\n");
    InOrderTraverse(T,Visit);
    printf("中序非递归遍历：\n");
    InOrderTraverse2(T,Visit);
    DestroyBiTree(T);
}