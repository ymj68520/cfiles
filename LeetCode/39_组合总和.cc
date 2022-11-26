#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        ans.clear();
        if(len == 0)    return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(candidates,0,len,target,path);
        return ans;
    }
    void dfs(const vector<int> &cadidates, int begin, int len, int target, vector<int> &path){
        if(!target){
            ans.push_back(path);
            return;
        }
        for(int i=begin;i<len;i++){
            if(target-cadidates[i] < 0) break;
            path.push_back(cadidates[i]);
            dfs(cadidates,i,len,target-cadidates[i],path);
            path.pop_back();
        }
    }
};