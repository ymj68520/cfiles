#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            if(i+1 < n && nums[i]!=nums[i+1])
                return nums[i];
        }
        return nums[n-1];
    }
    int singleNumber2(vector<int> &nums){
        int ans=0;
        for(const auto &x : nums)   ans ^= x;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,2,3};
    Solution sol;
    cout << sol.singleNumber(nums) << endl << sol.singleNumber2(nums) << endl;

    return 0;
}