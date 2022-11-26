
#include "./MGraph.h"
typedef MGraph Graph;
#define tety            // 定义标志变量 使得原头文件的元素定义失效
typedef VertexType TElemType;
#include "../Tree/CSTree/CSTree.h"  // 孩子兄弟二叉链表

bool visite[MAX_VERTEX_NUM];
// 深度优先生成树  
void DFSTree(Graph G,int v,CSTree *T){
    // 从第v个节点开始深度优先遍历图G，建立以T为根节点的二叉树（孩子兄弟二叉链表
    bool first = true;  // 树还没有第一个孩子节点的标志
    int w;
    CSTree p,q;     // 孩子兄弟二叉链表指针
    visite[v] = true;   // 顶点v已经被访问的标志
    for(w = FirstAdjVex(G,v);w>=0;w = NextAdjVex(G,v,w))    // w依次为v的邻接顶点
        if(!visite[w])  // 顶点w尚未被访问
        {
            p = (CSTree)malloc(sizeof(CSNode));
            p->data = GetVex(G,v);      // 将顶点v的值赋予孩子节点的data域
            p->firstchild = NULL;
            p->nextsibling = NULL;  // p的第一个孩子节点与第一个兄弟节点均为空
            if(first)   // 顶点w是顶点v的第一个未被访问的邻接顶点
            {
                (*T)->firstchild = p;   // 顶点w是根的第一个孩子节点
                first = false;  // 首孩子节点标志赋假
            }
            else    // 顶点w是顶点v的其他未被访问的邻接顶点
                q->nextsibling = p;     // 是上一邻接顶点的兄弟节点
            // for循环的第一次循环不通过此处，以后q已经赋值
            q = p;  // q指向p所指节点
            DFSTree(G,w,&q);    // 从第w个节点开始，深度优先遍历图G，建立二叉树
        }
}
// 深度优先森林
void DFSForest(Graph G,CSTree *T){
    // 建立无向图G的深度优先生成森林的（最左）孩子（下一个）兄弟链表T
    CSTree p,q; // 指针类型
    int v;
    (*T) = NULL;
    memset(visite,false,MAX_VERTEX_NUM*sizeof(bool));   // 初始化访问标志数组
    for(v=0;v<G.vexnum;v++)     // 对于G的所有节点
        if(!visite[v])  // 第v个顶点未曾被访问
        {
            // 将第v个顶点为新的生成树的根节点
            p = (CSTree)malloc(sizeof(CSNode));
            p->data = GetVex(G,v);  // 给根节点赋值
            p->firstchild = NULL;   // 节点的首孩子，首兄弟域为空
            p->nextsibling = NULL;  // 以下将p所指节点插到T中
            if(!T)  // p所指节点是第一课生成树的根节点
                (*T) = p;
            else    // p是其他生成树的根（前一颗树根的兄弟）
                q->nextsibling = p; // for循环第一个，T=NULL，不通过此处，以后q已有值
            q = p;
            DFSTree(G,v,&p);     // 建立以p为根的树
        }
}

