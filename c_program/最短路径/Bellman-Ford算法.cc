#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1010;  // 最大的结点个数
const int INF = 999999; // 假设的边的最大值
class Edge{
public:
    int from, to, dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct bellman_ford1{
    int d[MAXN],u[MAXN],v[MAXN];
    int n,m;
    int w[MAXN];
    void belfd(){
        for(int i=0;i<n;i++)    d[i] = INF;
        d[0] = 0;
        for(int k=0;k<n-1;k++){
            for(int i=0;i<m;i++){
                // 检查每条边
                int x = u[i], y = v[i];
                if(d[x]<INF)    d[y] = min(d[y],d[x]+w[i]);
            }
        }
    }
    bool inq[MAXN];
    int cnt[MAXN];
    int p[MAXN];
    vector<int> G[MAXN];
    vector<Edge> edges;
    bool bellman_ford(int s){
        queue<int> Q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)    d[i] = INF;
        d[s] = 0;
        inq[s] = true;
        Q.push(s);

        while(!Q.empty()){
            int u = Q.front();Q.pop();
            inq[u] = false;
            for(int i=0;i<G[u].size();i++){
                Edge &e = edges[G[u][i]];
                if(d[u]<INF && d[e.to]>d[u]+e.dist){
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if(!inq[e.to]){
                        Q.push(e.to);
                        inq[e.to] = true;
                        if(++cnt[e.to] > n)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};