#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

/*
 * 建图，边权重为cnt+1（cnt+1条边，每边权值为1）
 * 使用dijkstra计算单源最短路径
 * 对于每个点，如果可以到达，则计入答案
 * 对每条边u-v，如果从u出发可以走a步，从v出发可以走b步，则可以到达min(a+b,cnt)
 */
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int> > > graph(n);
        for(auto &e : edges){
            graph[e[0]].push_back({e[1],e[2]+1});
            graph[e[1]].push_back({e[0],e[2]+1});
        }
        auto dijkstra = [](vector<vector<pair<int,int> > > &graph){
            vector<int> dist(graph.size(),INT_MAX);
            dist[0] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > q;
            q.push({0,0});
            while(!q.empty()){
                auto [d,x] = q.top();
                q.pop();
                if(d>dist[x])   continue;

                for(auto[y, wt] : graph[x]){
                    int new_d = dist[x] + wt;
                    if(new_d < dist[y]){
                        dist[y] = new_d;
                        q.emplace(new_d, y);
                    }
                }
            }
            return dist;
        };
        auto dist = dijkstra(graph);
        int ans = 0;
        for (int d : dist)
            if (d <= maxMoves) // 这个点可以在 maxMoves 步内到达
                ++ans;
        for (auto &e: edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = max(maxMoves - dist[u], 0);
            int b = max(maxMoves - dist[v], 0);
            ans += min(a + b, cnt); // 这条边上可以到达的节点数
        }
        return ans;
    }
};