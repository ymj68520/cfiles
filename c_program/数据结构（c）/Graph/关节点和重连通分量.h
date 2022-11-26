#include "./ALGraph.h"
// 删去一个顶点及与其相关的边之后，该图的一个连通分量变成两个或者两个以上的
// 连通分量则称这个结点为关节点(割点)。

// 一个没有关节点的图称为重连通图，即图中的每一对节点之间至少存在两条路径。
// 若删除一个图的k个节点之后才能破坏图的连通性，则称此图的连通度为k。

// 由深度优先生成树可得出两类关节点的特性：
//  1. 若生成树的根有两棵或两颗以上的子树，则此根顶点必为关节点。因为图中不存在联结不同子树
//     中顶点的边，因此，若删去跟顶点，生成树便变为生成森林。
//  2. 若生成树中某个非叶子节点v，其某棵子树的根和子树中的其他节点均没有指向v的祖先的回边
//     则v为关节点。因为，若删除v则其子树和图的其他部分被分割开来。
/* 
    定义 visited[v] 为深度优先搜索遍历连通图时访问顶点v的次序号。
    定义：
    low(v) = Min{
        visited[v],low[w],visited[k];
        // w是顶点v在深度优先生成树上的孩子节点
        // k是顶点v在深度优先生成树上由回边联结的祖先节点
        // (v,w)∈Edge
        // (v,k)∈Edge       
    }
    若对于某个顶点v，若存在孩子节点w且low[w]>=visited[v]，则该顶点v必为关节点。
        因为当w是v的孩子节点时，low[w]>=visited[v]，表明w及其子孙均无指向v的祖先的回边
*/

static int count,lowcount=1;   // 全局量count对访问顺序计数，lowcount对求得low值的顺序计数
static int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];
// 全局数组，low[]存顶点的low值，lowOrder存顶点求low值的顺序
static int visited[MAX_VERTEX_NUM];    // 访问标志数据（全局量）

// 从第v0个顶点出发深度优先遍历图，查找并输出关节点
void DFSArticul(ALGraph G,int v0){
    int min,w;
    ArcNode *p;
    visited[v0] = min = ++count;    // v0是第count个访问的顶点，min的初值为v0的访问顺序
    for(p = G.vertices[v0].firstarc;p;p=p->nextarc) // 依次对v0的每个邻接顶点检查
    {
        w = p->data.adjvex; // w为v0的邻接顶点位置
        if(visited[w]==0)   // w未曾访问，是v0的孩子
        {
            DFSArticul(G,w);// 从第w个节点出发深度优先遍历图G，查找并输出关节点，返回求得low[w]
            if(low[w]<min)  // 如果v0的孩子节点w的low值小，说明孩子节点还与其他节点相邻
                min = low[w];   // 取min的值为孩子节点的low[]，则v0不是关节点
            else if(low[w]>=visited[v0])    // v0的孩子节点w只与v0相连，则v0是关节点
                printf("%d %s\n",v0,G.vertices[v0].data.name);  // 输出
        }
        else if(visited[w]<min) // w已访问，则w是v0在生成树上的祖先，它的访问顺序必然小于min
            min = visited[w];   // 故取min为visited[w]
    }
    low[v0] = min;  // v0的low值为三者中的最小值
    lowOrder[v0] = lowcount++;
    // 记录v0求得low[]值的顺序（附加），总是在返回主调函数之前求得low[]
}
void FindArticul(ALGraph G){
    // 连通图G以邻接表作存储结构，查找并输出G上全部关节点。全局量count 对访问计数。
    int i,v;
    ArcNode *p;
    count = 1;
    visited[0] = count; // 设定邻接表上0号顶点为生成树的根，第一个被访问
    for(i=0;i<G.vexnum;i++)
        visited[i] = 0; // 其余结点都未被访问设为0
    p = G.vertices[0].firstarc; // p指向根结点的第一个邻接顶点
    v = p->data.adjvex; // v是根节点的第一个邻接顶点的序号
    DFSArticul(G,v);    // 从第v顶点出发深度优先查找关节点
    if(count<G.vexnum)  // 由根节点的第一个邻接顶点深度优先遍历G,访问的顶点数少于G的定点数
    { // 说明生成树的根有至少两棵子树，则根是关节点
        printf("%d %s\n",0,G.vertices[0].data.name);
        while(p->nextarc){
            p = p->nextarc;
            v = p->data.adjvex;
            if(visited[v]==0)
                DFSArticul(G,v);    
        }
    }
}
