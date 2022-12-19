#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(const auto & e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            if(vis[q.front()]){
                q.pop();
                continue;
            }
            int start = q.front();
            if(start == destination)    return true;
            q.pop();
            vis[start] = 1;
            for(const auto next:graph[start])   q.push(next);
        }
        return false;
    }
};