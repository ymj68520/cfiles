#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int cnt = 0;
        int dp[n];memset(dp,0,sizeof(dp));
        for(int i=2;i<n;i++){
            if((nums[i]-nums[i-1]) == (nums[i-1]-nums[i-2])){
                dp[i] = dp[i-1] + 1;
                cnt += dp[i];
            }
            
        }
        return cnt;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,6,8};
    Solution sol;

    cout << sol.numberOfArithmeticSlices(nums) << endl;
}