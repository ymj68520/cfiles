/*
    设S为已求得最短路径的终点集合，则有：
        下一条最短路径（设其终点为x）或者是弧(v,x)，
        或者是中间只经过S中顶点而最后到达顶点x的路径。
            即：
                D[j] = Min{ D[i] | v_i∈V-S };
                    其中D[i]为弧(v,v_i)上的权值或者是D[k](v_k∈S)和弧(v_k,v_i)上的权值之和

    算法描述如下：（邻接矩阵）
        1.  邻接矩阵arcs[i][j]表示弧(v_i,v_j)的权值。若(v_i,v_j)不存在则置位正无穷。
            S为已经找到从v出发的最短路径的集合，它的初始状态为空。
            那么从v出发到图上其各顶点（终点）v_i,可能达到的最短路径初始值为：
                D[i] = arcs[LocateVex(G,v)][i];         // 即为v与各顶点的直接距离，无则置位无穷
        2.  选择v_j, 使得
                D[j] = Min{ D[i] | v_i∈V-S };
            v_j就是当前求得的一条从v出发的最短路径的终点。令
                S = S ∪ {j};
        3.  修改从v出发到集合V-S上任一顶点v_k可达的最短路径长度。如果：
                D[j] + arcs[j][k] < D[k];
            则修改D[k]为：
                D[k] = D[j] + arcs[j][k];
        4.  重复2. 3. 操作共n-1次。由此求得从v到图上其余各顶点的最短路径是依路径长度递增的序列。
*/

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

typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    // 路径矩阵，二维数组
typedef VRType ShortPathTable[MAX_VERTEX_NUM];  // 最短距离表，一维数组

// 使用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
// 若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点
// final[v]为true当且仅当v∈S，即已经求得从v0到v的最短路径
void ShortPath_DIJ(MGraph G,int v0,PathMatrix P,ShortPathTable D){
    int v,w,i,j;
    VRType min;
    bool final[MAX_VERTEX_NUM];
    // 辅助矩阵，为真表示该顶点到v0的最短距离已经求出，初值为假
    for(v=0;v<G.vexnum;v++){
        final[v] = false;
        D[v] = G.arcs[v0][v].adj;   // D[]存放v0到v的最短距离，初始值为v0到v的直接距离
        for(w=0;w<G.vexnum;w++)
            P[v][w] = false;    // 设P[][]初值为false，没有路径
        if(D[v]<INFINITY)   // v0到v有直接路径
            P[v][v0] = P[v][v] = true;
            // 一维数组P[v][]表示源点v0到v最短路径通过的顶点，目前通过v0和v两顶点
    }
    D[v0] = 0;  // v0到v0距离为0
    final[v0] = true;   // v0并入S集合
    for(i=1;i<G.vexnum;i++) //对于其余vexnum-1个顶点
    {   // 开始主循环，每次求得v0到某个顶点v的最短路径，并将v并入s集合
        min = INFINITY; // 当前所知的离v0最近距离，设初始值为无穷
        for(w=0;w<G.vexnum;w++) // 对所有顶点检查
            if(!final[w] && D[w] < min) // 在S集合之外的顶点（其final[]=false)中
            {   // 找离v0最近的顶点w，并将其赋值给v，距离赋值给min
                v = w;  // 在s集合之外的离v0最近的顶点序号
                min = D[w]; // 最近的距离
            }
        final[v] = true;    // 将v并入s集合
        for(w=0;w<G.vexnum;w++) // 根据新并入的顶点，更新不在S集的顶点到v0的距离和路径数据
            if(!final[w] && min < INFINITY && G.arcs[v][w].adj<INFINITY &&
            (min+G.arcs[v][w].adj)<D[w] )
            {   // w 不属于S集且v0到v再到w的距离 < 目前v0到w的距离
                D[w] = min + G.arcs[v][w].adj;  // 更新D[w]
                for(j=0;j<G.vexnum;j++) // 修改P[w]，v0到w经过的顶点包括v0到v经过的顶点再加上顶点w
                    P[w][j] = P[v][j];
                P[w][w] = true;  
            }
    }
}