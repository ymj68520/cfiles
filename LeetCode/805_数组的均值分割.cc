#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return false;
        int s = accumulate(nums.begin(),nums.end(),0);
        for(int &num:nums) num = num * n - s;

        int m = n >> 1;
        unordered_set<int> vis;
        // for(int i=1;i< 1<<m ; ++i){
        for(int i=1;i< 1<<(m-1) ; ++i){
            int t = 0;
            for(int j=0;j<m;++j)    if(i>>j & 1) t += nums[j];
            if(t==0)    return true;
            vis.insert(t);
        }

        for(int i=1;i< 1<<(n-m); ++i){
            int t=0;
            for(int j=0;j<(n-m);++j)    if(i>>j & 1)    t+=nums[m+j];
            // 排除全选另一边
            // if(t==0 || (i != (1<<(n-m))-1 && vis.count(-t)) )   return true;
            // 不需要排除，只因前半部分未全遍历
            if(t==0 || vis.count(-t))     return true;

        }

        return false;
    }
};

int main(){
    vector<int> nums = {3,1};
    Solution sol;
    cout << sol.splitArraySameAverage(nums) << endl;

    return 0;
}