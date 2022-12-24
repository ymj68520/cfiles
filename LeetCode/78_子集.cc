#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int> > ans;
    vector<int> path;
    void dfs(vector<int>& nums,int index,vector<int>& path){
        ans.push_back(path);
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i+1,path);
            path.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();path.clear();
        dfs(nums,0,path);
        return ans;
    }
};