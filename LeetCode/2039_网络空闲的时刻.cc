#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int> > vertex(n);
        for(const auto &e : edges){
            vertex[e[0]].push_back(e[1]);
            vertex[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        queue<pair<int,int> > q;
        q.emplace(0,0);
        vis[0] = true;
        int ans = 0;
        while(!q.empty()){
            auto [c,time] = q.front();
            q.pop();
            if(c != 0 ){
                int cost = ((2*time-1)/patience[c]) * patience[c] + 2 * time;
                ans = max(ans, cost);
            }
            for(const int &next : vertex[c]){
                if(!vis[next]){
                    vis[next] = true;
                    q.emplace(next,time+1);
                }
            }
        }
        return ans+1;

    }
};