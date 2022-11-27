#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
#include <utility>

using namespace std;

const int INF = INT_MAX - 114514;

void bellman_ford(int n, vector<int> dist, vector<int> w,
                  vector<int> u, vector<int> v){
    for(auto &d:dist)   d = INF;
    dist[0] = 0;
    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            int x = u[i], y = v[i];
            if(dist[x] < INF)
                dist[y] = min(dist[y],dist[x] + w[i]);
        }
    }
}
vector<vector<int> > G;
vector<vector<int> > edges;
bool bellman_ford(int s, int n,vector<int> dist, vector<int> w,
                  vector<int> u, vector<int> v){
    queue<int> Q;
    int inq[n],cnt[n];
    int p[n];
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n;i++)   dist[i] = INF;
    dist[s] = 0;
    inq[s] = true;

    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int i=0;i<G[u].size();i++){
            auto & e = edges[G[u][i]];
            if(dist[u]<INF && dist[e[1]] > dist[u]+e[2]){
                dist[e[1]] = dist[u] + e[2];
                p[e[1]] = G[u][i];
                if(!inq[e[1]]){
                    Q.push(e[1]);
                    inq[e[1]] = true;
                    if(++cnt[e[1]] > n) return false;
                }
            }
        }
    }
    return true;
}