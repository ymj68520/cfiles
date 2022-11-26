#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int> > vertex(n);
        for(const auto &v : graph)
            vertex[v[0]].push_back(v[1]);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == target)   return true;
            for(const auto &v : vertex[cur])
                q.push(v);
        }
        return false;
    }
};