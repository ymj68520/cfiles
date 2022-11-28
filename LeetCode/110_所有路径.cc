#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        // vector<int> vis(n,0);
        // vis[0] = 1;
        function<void(int,vector<int>)> dfs = [&](int index,vector<int> path){
            if(index == n-1){
                // path.push_back(index);
                ans.push_back(path);
                // path.pop_back();
                return;
            }
            for(auto &next : graph[index]){
                path.push_back(next);
                dfs(next, path);
                path.pop_back();
            }
        };
        dfs(0,path);
        return ans;        
    }
};

int main(){
    vector<vector<int> > g = {{1},{}};
    Solution sol;
    vector<vector<int>> ans = sol.allPathsSourceTarget(g);

    for(auto &x:ans){
        for(auto &y:x)  cout << y << ' ';
        cout << endl;
    }

    return 0;
}