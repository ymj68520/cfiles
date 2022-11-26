#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    int flag;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(candidates,0,path,target);
        return ans;
    }
    void dfs(const vector<int> &cadidates, int start, vector<int> &path, int target){
        if(!target){
            ans.push_back(path);
            return;
        }
        if(start == cadidates.size())   return;
        for(int i=start;i<cadidates.size();++i){
            if(target < cadidates[i])   break;
            if(cadidates[i] == flag)    continue;
            path.push_back(cadidates[i]);
            dfs(cadidates,i+1,path,target-cadidates[i]);
            flag = path.back();
            path.pop_back();
        }
    }
};

int main(){
    vector<int> can = {2,5,2,1,2};
    int tar = 5;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(can,tar);
    for(auto &x:ans){
        for(auto &y:x)  cout << y << " ";
        cout << endl;
    }
    return 0;
}