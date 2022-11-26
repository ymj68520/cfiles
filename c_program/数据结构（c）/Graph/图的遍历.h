
#include "./MGraph.h"
#include <stdbool.h>
#include <string.h>

#ifndef MAX_VERTEX_NUM
#define MAX_VERTEX_NUM 20
#endif

bool visite[MAX_VERTEX_NUM];        // 访问标志数组
void (* VisitFunc)(VertexType);     // 函数变量
#ifndef Graph
#define Graph MGraph
#endif
// 深度优先遍历
void DFS(Graph G,int v){
    // 从第v个顶点出发递归的深度优先遍历图G
    int w;
    visite[v] = true;   // 设置访问标志位true（已访问）
    VisitFunc(GetVex(G,v)); // 访问第v个顶点
    for(w = FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))  // 从顶点v的第一邻接顶点开始
        if(!visite[w])  // 邻接顶点w尚未被访问
            DFS(G,w);   // 对v的尚未访问的序号为w的邻接顶点递归调用DFS（访问w）
}

// 若图G存在 Visit是顶点的应用函数  
// 则从第一个顶点起深度优先遍历图G，并对每个顶点调用函数Visit一次仅且一次
void DFSTraverse(Graph G,void(*Visit)(VertexType)){
    int v;
    VisitFunc = Visit;  // 使用全局变量VisitFunc，使DFS不必设函数指针
    memset(visite,false,MAX_VERTEX_NUM*sizeof(bool));
    // visite数组已经初始化 memset(visite,false,MAX_VERTEX_NUM*sizeof(bool));
    for(v=0;v<G.vexnum;v++) // 对图的所有节点
        if(!visite[v])  // 顶点v尚未被访问
            DFS(G,v);   // 调用DSF
    printf("\n");
}

// 广度优先遍历
typedef int QElemType;  // 定义整型为队列元素（节点的序号）
#include "../queue/queue.h" // 队列
// 若图G存在，Visit是顶点的应用函数
// 则从第一个顶点起，按广度优先非递归遍历图G，并对每个顶点调用Visit函数一次仅且一次
void BFSTraverse(Graph G,void(* Visit)(VertexType)){
    int v,u,w;
    LinkQueue Q;    // 使用辅助队列Q和访问标志数组visite
    InitQueue(&Q);  // 初始化队列
    // 初始化标志数组
    memset(visite,false,MAX_VERTEX_NUM*sizeof(bool));
    for(v=0;v<G.vexnum;v++) // 对图G的所有顶点
        if(!visite[v])  // 顶点v尚未被访问
        {
            visite[v] = true;   // 设置标志数组已被访问
            Visit(GetVex(G,v)); // 访问节点v
            EnQueue(&Q,v);     // v入队
            while(!QueueEmpty(Q))   // 队列不空
            {
                DeQueue(&Q,&u); // 对头元素出队
                for(w = FirstAdjVex(G,u);w>=0;w = NextAdjVex(G,u,w))    // 从u的第一个邻接顶点w起
                    if(!visite[w])  // w为u的尚未访问邻接顶点
                    {
                        visite[w] = true;   // 设置为已访问
                        Visit(GetVex(G,w)); // 访问顶点w
                        EnQueue(&Q,w);   // w入队
                    }
            }
        }
        printf("\n");
}
