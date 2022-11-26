// 构造最优二叉树的算法(赫夫曼算法)：
// 1.将每个带有权值的结点作为一颗新二叉树，树的权值为结点的权值
// 2.将其中两颗权值最小的树组成一颗新二叉树，权值为子树的权值和
// 3.重复(2.)直到所有节点都在一棵树上，这棵树就是赫夫曼树

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Status bool
#define OK true
#define ERROR false
// 静态三叉链表二叉树结构
typedef struct{
    int weight;    // 节点权值
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;   // 动态分配数组存储赫夫曼树

typedef char ** HuffmanCode;    // 动态分配数组存储赫夫曼编码表

// 严书中的复刻     Select 未实现
// 在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
void Select(HuffmanTree *HT,int i,int *s1,int *s2);
void HuffmanCoding_yanshu(HuffmanTree *HT, HuffmanCode *HC, int *w, int n){
    // w存放n个字符的权值（均>0），构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
    if(n<=1)    return;
    int m = 2*n-1;      // 节点个数
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p;
    int i;
    for(p = (*HT)+1,i=1;i<=n;++i,++p,++w){
        (*p).weight = *w;   // 赋权值
        (*p).parent = 0;    // 双亲域为空（根节点
        (*p).lchild = (*p).rchild = 0;  // 左右孩子均为空（叶子结点，单节点树
    }
    for(;i<=m;++i,++p)
        (*p).parent = 0;    // i从n+1到m
    for(i=n+1;i<=m;++i){
        // 建赫夫曼树
        int s1,s2;
        // 在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号为s1和s2
        //Select(HT,i-1,&s1,&s2);
        HT[s1]->parent = i;
        HT[s2]->parent = i;
        HT[i]->lchild = s1;
        HT[i]->rchild = s2;
        HT[i]->weight = HT[s1]->weight+HT[s2]->weight;
    }
    // ----从叶子到根逆向求每个字符的赫夫曼编码
    *HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
    char *cd = (char *)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    for(i=1;i<n;++i){
        int start = n-1;
        int c,f;
        for(c = i,f = HT[i]->parent;f!=0;c=f,f = HT[f]->parent)
            if(HT[f]->lchild ==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (HuffmanCode)malloc((n-start)*sizeof(char));
        strcpy(*HC[i],cd);
    }

    free(cd);
}

// 解析
#define Order   // 定义Order
// 返回赫夫曼树t的前i个结点中权值最小的根节点序号，函数select（）调用
int min(HuffmanTree t,int i){
    int j,m;
    unsigned k = __UINT16_MAX__;    // k最小权值，初值取为不小于可能的值（无符号整数最大值）
    for(j=1;j<=i;j++)
        // 对于前i个结点
        if(t[j].weight<k && t[j].parent == 0)   // t[j]的权值小于k，又是树的根节点
        {
            k = t[j].weight;    // t[j]的权值赋给k
            m = j;              // 序号赋给m
        }
        t[m].parent = 1;        // 给选中的根节点的双亲赋非零值，避免第二次查找该节点
        return m;               // 返回权值最小的根节点序号
}
void select_t(HuffmanTree t,int i,int *s1,int *s2){
    #ifdef Order
    int j;
    #endif
    *s1 = min(t,i);     // 权值最小
    *s2 = min(t,i);     // 权值次小
    #ifdef  Order
    if(s1>s2){  // s1的序号大于s2的
        j = *s1;
        *s1 = *s2;
        *s2 = j;
    }
    #endif
}
// 创建赫夫曼树
void CreatHuffmanTree(HuffmanTree *HT,int *w,int n){
    int m,i,s1,s2;
    unsigned c;
    HuffmanTree p;
    if(n<=1)    // 叶子节点数不大于1
        return;
    m =2*n-1;   // n个叶子节点的赫夫曼树共有m个结点
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(p = (*HT)+1,i = 1;i<=n;i++,p++,w++){
        // 从一号单元开始到0号单元 给叶子结点赋值
        // p的初始值指向1号单元
        (*p).weight = *w;   // 赋权值
        (*p).parent = 0;    // 双亲域为空（根节点
        (*p).lchild = (*p).rchild = 0;  // 左右孩子均为空（叶子结点，单节点树
    }
    for(;i<=m;i++,p++){
        (*p).parent = 0;    // i从n+1到m
    }
    for(i=n+1;i<=m;i++) // 开始创建
    {
        select_t(*HT,i-1,&s1,&s2);
        HT[s1]->parent = HT[s2]->parent = i;
        HT[i]->lchild = s1;
        HT[i]->rchild = s2;
        HT[i]->weight = HT[s1]->weight+HT[s2]->weight;
    }
}
// 求编码
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n){
    int start;
    unsigned c,f;
    char *cd;
    int i;
    *HC = (HuffmanCode)malloc((n+1)*sizeof(char *));    // 分配n个字符编码的头指针相量([0])不用
    cd = (char *)malloc(n*sizeof(char));           // 分配求编码的工作空间
    cd[n-1] = '\0';
    for(i=1;i<=n;i++){
        // 逐个字符求编码
        start = n-1;
        for(c=i,f = (*HT[i]).parent;f!=0;c=f,f=(*HT[f]).parent)
            if((*HT[f]).lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        *HC[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(*HC[i],&cd[start]);
    }
    free(cd);    
}