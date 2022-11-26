#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum=0;
    for(auto& x:nums)   sum+=x;
    if(abs(target) > sum)   return 0;
    
    int len = 2*sum+1;
    int dp[n][len];
    if(nums[0]){
        dp[0][sum+nums[0]] = 1;
        dp[0][sum-nums[0]] = 1;
    }
    else
        dp[0][sum] = 2;   // 0+0=0 0-0=0
    for(int i=1;i<n;i++){
        for(int j=0;j<len;j++){
            int l = (j - nums[i]) >= 0 ? j - nums[i] : 0;
            int r = (j + nums[i]) < len ? j + nums[i] : 0;
            dp[i][j] = dp[i-1][l] + dp[i-1][r];
        }
    }
    return dp[n-1][sum+target];
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums,target) << endl; 
}