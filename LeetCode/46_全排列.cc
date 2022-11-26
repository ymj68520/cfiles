#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        do
            ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()));

        return ans;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute1(vector<int>& nums){
        vector<vector<int> > res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }
};

int main(){
    vector <int> nums = {1,2,3};
    Solution sol;
    vector<vector<int> > ans = sol.permute(nums);
    for(auto x:ans){
        for(auto y:x)   cout << y << ' ';
        cout << endl;
    }
    return 0;
}