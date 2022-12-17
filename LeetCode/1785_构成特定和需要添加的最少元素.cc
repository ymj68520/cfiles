#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = accumulate(nums.begin(),nums.end(),0l);
        // for(const auto &num:nums)   sum+=num;
        // long diff = abs(sum-goal);
        return (abs(sum-goal)+limit-1)/limit;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,2,5,1,-2};
    int limit = 5;
    int goal = 126614243;
    cout << sol.minElements(nums,limit,goal) << endl;

    return 0;
}