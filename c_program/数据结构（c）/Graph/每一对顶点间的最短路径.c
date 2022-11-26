#include "MGraph.h"

// 求由图G的起点到终点最短路径沿途所经过的顶点
void MakePath(MGraph G,bool P[],int i,int j){
    int k,MinNum,begin = i; // 起点序号赋值给begin（当前起点）
    VRType Min; // 存begin到可能经过的顶点之间的最短路径
    while(begin != j){
        Min = INFINITY; // 设置初始值为正无穷（整型最大值）
        for(k=0;k<G.vexnum;k++) // 查找顶点begin的所有邻接顶点
            if(G.arcs[begin][k].adj<Min && P[k])
            {   // begin到k有较短的直接通路，且k在i到j的最短路径上
                Min = G.arcs[begin][k].adj; // 修改Min为较小值
                MinNum = k; // 较小值顶点序号赋值给MinNum
            }
        if(Min == INFINITY) // 起点[i]到终点[j]之间没有通路
            break;  // 退出while循环
        printf("%s",G.vexs[MinNum].name);   // 输出最短路径的顶点
        if(MinNum != j) // Minum 不是终点
            printf(" -> ");
        P[MinNum] = false;  // 缩短路径（不在回头找[MinNum]
        begin = MinNum; // 经过的顶点序号赋值给begin，作为当前起点继续查找
    }
    printf("\n");
}

typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];    // 3维数组
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    // 2维数组

// 用floyd算法求有向网G中各顶点v和w之间的最短路径P[v][w][]及其带权长度D[v][w]
// 若P[v][w][u]为true，则u是从v到w当前求得最短路径上的顶点。
void ShortestPath_FLOYD(MGraph G, PathMatrix P, DistancMatrix D){
    int u,v,w,i;
    for(v=0;v<G.vexnum;v++) // 各对顶点之间初始已知路径及距离
        for(w=0; w<G.vexnum;w++){
            D[v][w] = G.arcs[v][w].adj; // 顶点v到顶点w的直接距离
            for(u=0;u<G.vexnum;u++)
                P[v][w][u] = false; // 路径矩阵初值
            if(D[v][w]<INFINITY)    // 从v到w有直接路径
                P[v][w][v] = P[v][w][w] = true;     // 由v到w的路径经过v和w两点
        }
    for(u=0;u<G.vexnum;u++)
        for(v=0;v<G.vexnum;v++)
            for(w=0;w<G.vexnum;w++)
                if(u!=v && u!=w && v!=w && D[v][u]<INFINITY && D[u][w]<INFINITY
                    && D[v][u] + D[u][w] < D[v][w])
                {
                    D[v][w] = D[v][u] + D[u][w];    // 更新最短距离
                    for(i=0;i<G.vexnum;i++)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];
                        // 从v到w的路径经过从v到u和从u到w的所有路径
                }
}

int main(){
    MGraph g;
    int i,j,k;
    PathMatrix p;   // 三维数组
    DistancMatrix d;    // 二维数组
    bool *path;
    CreateFromFile(&g,"f7-6.txt",0);
    for(i=0;i<g.vexnum;i++)
        g.arcs[i][i].adj = 0;
    Display(g);
    ShortestPath_FLOYD(g,p,d);
    printf("d 矩阵 ：\n");
    for(i=0;i<g.vexnum;i++){
        for(j=0;j<g.vexnum;j++)
            if(d[i][j] == INFINITY)
                printf(" ∞");
            else
                printf("%4d",d[i][j]);
        printf("\n");
    }
    path = (bool*)malloc(g.vexnum * sizeof(bool));
    for(i=0;i<g.vexnum;i++)
        for(j=0;j<g.vexnum;j++)
            if(i!=j){
                printf("%s -> %s: p[%d][%d][]=",g.vexs[i].name,g.vexs[j].name,i,j);
                for(k=0;k<g.vexnum;k++){
                    printf("%2d, ",p[i][j][k]);
                    path[k] = p[i][j][k];
                }
                printf("最短路径 = %2d, ",d[i][j]);
                printf("经过的顶点：");
                MakePath(g,path,i,j);
            }
    return 0;
}