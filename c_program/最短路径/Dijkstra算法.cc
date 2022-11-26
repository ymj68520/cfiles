#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
*   清除所有标号的结点
*   设d[0] = 0; 其他d[i]=INF;
*   循环n次{
*       在所有未标号节点中，选出d值最小的结点x
*       给节点x标记
*       对于从x出发的所有边(x,y)，更新d[y] = min(d[y],d[x]+w(x,y)); 
*   }
*/

const int MAXN = 1010;  // 最大的结点个数
const int INF = 999999; // 假设的边的最大值
struct Dij{
    int d[MAXN];        // 起始节点到其他节点的最短路径
    bool v[MAXN];       // 表示节点v[i]还未被访问，未被方位为false
    int w[MAXN][MAXN];  // w[u][v]表示边(u,v)的权值。w=INF时表示此边不存在。
    // O(n^2)
    void Dijkstra(int n){
        memset(v,0,sizeof(v));
        d[0] = 0;
        for(int i=1;i<n;i++)    d[i] = INF;
        for(int i=0;i<n;i++){
            int x,m=INF;
            for(int y=0;y<n;y++)    if(!v[y] && d[y] <= m) m = d[x=y];
            v[x] = 1;
            for(int y=0;y<n;y++)    d[y] = min(d[y],d[x]+w[x][y]);
        }
    }
};
// O(mlogn)
int n,m;
const int MAXM = 1111;
int first[MAXM];    // first[u]保存节点u的第一条边的编号
int u[MAXM],V[MAXM],W[MAXM],nexte[MAXM]; // next[e] 表示编号为e的边的下一条边的编号
// 读入有向图的边列表，并建立图
void read_graph(){
    scanf("%d%d",&n,&m);
    memset(first,-1,sizeof(first));
    for(int e=0;e<m;e++){
        scanf("%d%d%d",u+e,V+e,W+e);
        nexte[e] = first[u[e]];
        first[u[e]] = e;
    }
}
class Edge{
public:
    int from, to, dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
class Dijkstra{
public:
    int n,m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool done[MAXN];        // 是否已经永久标号
    int d[MAXN];    // s到各个节点的距离
    int p[MAXN];    // 最短路中的上一条弧

    void init(int n){
        this->n = n;
        for(int i=0;i<n;i++)    G[i].clear();
        edges.clear();
    }    

    void AddEdge(int from,int to, int dist){
        edges.push_back(Edge(from,to,dist));
        m = edges.size();   // m-1为当前插入的边的标号
        G[from].push_back(m-1);
    }
    struct HeapNode{
        int d,u;
        bool operator < (const HeapNode & rhs) const {
            return d > rhs.d;
        }
    };
    void dijikstra(int s){
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++) d[i] = INF;
        d[s] = 0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty()){
            HeapNode x = Q.top();Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i=0;i>G[u].size();i++){
                Edge &e = edges[G[u][i]];
                if(d[e.to] > d[u]+e.dist){
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
    
};


