#include "MGraph.h"

typedef struct{
    // 记录从顶点集U到V-U的代价最小的边的辅助数组
    int adjvex; // 顶点集U中到该点为最小权值的那个顶点的序号
    VRType lowcost; // 那个顶点的到该点的权值（最小权值）
}minside[MAX_VERTEX_NUM];
int minimum(minside SZ,MGraph G){
    // 求SZ.lowcost的最小正值，并返回其在SZ的序号
    int i=0,j,k,min;
    while(!SZ[i].lowcost)   // 找第一个值不为0的SZ[i].lowcost的序号
        i++;
    min = SZ[i].lowcost;    // 标记第一个不为0的值
    k = i;  // k标记该值的序号
    for(j = i+1; j<G.vexnum;j++)    // 继续向后查找
        if(SZ[j].lowcost>0 && SZ[j].lowcost<min)    // 找到新的更小值
        {
            min = SZ[j].lowcost;    // 标记该值
            k = j;  // k标记更小值的位置
        }
    return k;   // 返回最小值的序号
}
// 普里姆算法
void MinSpanTree_PRIM(MGraph G,VertexType u){
    // 使用普里姆算法从顶点u出发构造网G的最小生成树T 输出T的各条边
    int i,j,k;
    minside closedge;
    k = LocateVex(G,u); // 顶点u的序号
    for(j=0;j<G.vexnum;j++) // 辅助数组初始化
    {
        closedge[j].adjvex = k; // 顶点u的序号赋值给closedge[j].adjvex
        closedge[j].lowcost = G.arcs[k][j].adj; // 顶点u到该点的权值
    }
    closedge[k].lowcost = 0;    // 初始，U={u}，U中的顶点到集合U的权值为0
    printf("最小代价生成树的各条边为: \n"); // 
    for(i=1;i<G.vexnum;i++) // 选择其余G.vexnum-1个节点（i仅计数
    {
        k = minimum(closedge,G);    // 求出最小生成树T的下一个结点，第k顶点
        printf("(%s——%s)\n",G.vexs[closedge[k].adjvex].name,G.vexs[k].name);
        // 输出最小生成树T的边
        closedge[k].lowcost = 0;    // 第k顶点并入U集
        for(j=0;j<G.vexnum;j++)
            if(G.arcs[k][j].adj<closedge[j].lowcost)    // 新顶点并入U集后重新选择最小边
            {
                closedge[j].adjvex = k;
                closedge[j].lowcost = G.arcs[k][j].adj;
            }
    }
}

// 克鲁斯卡尔算法求无向连通网的最小生成树
typedef struct{
    // 图的边信息存储结构
    int a,b;    // 边的两个顶点序号
    VRType weight;  // 边的权值
}side;

// 克鲁斯卡尔算法
void Kruskal(MGraph G){
    int set[MAX_VERTEX_NUM],senumber=0,sb,i,j,k;
    side se[MAX_VERTEX_NUM*(MAX_VERTEX_NUM-1)/2];   // 存储边信息的一维数组
    for(i=0;i<G.vexnum;i++) // 查找所有的边，并根据权值升序插到se中
        for(j=i+1;j<G.vexnum;j++)   // 无向网，只在上三角查找
            if(G.arcs[i][j].adj<INFINITY)   // 顶点[i][j]之间有边
            {
                k = senumber-1; // k指向se的最后一条边
                while(k>=0) // k仍指向se的边
                    if(se[k].weight>G.arcs[i][j].adj)   // VRType == int
                    {   // k所指边的权大于刚找到的边的权值
                        se[k+1] = se[k];    // k所指的边向后移
                        k--;    // k指向前一条边
                    }else   // k所指边的权值不大于刚找到的边的权值
                        break;  // 跳出while循环
                se[k+1].a = i;  // 刚找到的边的信息按权值升序插入se
                se[k+1].b = j;
                se[k+1].weight = G.arcs[i][j].adj;
                senumber++; // se的边数加一
            }
    printf("i se[i].a se[i].b se[i].weight\n");
    for(i=0;i<senumber;i++)
        printf("%d %4d %7d %9d\n",i,se[i].a,se[i].b,se[i].weight);
    for(i=0;i<G.vexnum;i++) // 对于所有节点
        set[i] = i; // 设置初态，各顶点分别属于各个集合
    printf("最小代价生成树的各条边为\n");
    j=0;    // j指示se当前要并入最小生成树的边的序号，初值为0
    k=0;    // k指示当前构成最小生成树的边数
    while(k<G.vexnum-1) // 最小生成树应有vexnum-1条边
    {
        if(set[se[j].a]!=set[se[j].b])  // j所指边的两个顶点不属于同一个集合
        {   // 输出该边
            printf("（%s——%s）\n",G.vexs[se[j].a].name,G.vexs[se[j].b].name);
            sb = set[se[j].b];  // 将该边的顶点se[j].b当前所在的集合赋给sb
            for(i=0;i<G.vexnum;i++)
                if(set[i] == sb)    // 与顶点se[j].b在同一个集合中
                    set[i] = set[se[j].a];  // 将此顶点并入顶点se[j].a所在集合中
            k++;    // 当前构成最小生成树的边数+1
        }
        j++;    // j指示se下一条要并入最小生成树的边的序号
    }
}