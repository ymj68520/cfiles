#include "LeetCode.h"

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<int>& nums, int start) {
        if(start > nums.size()) return;
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if(i!=start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();path.clear();
        sort(nums.begin(), nums.end()); // 去重需要排序
        dfs(nums, 0);
        return result;
    }
};