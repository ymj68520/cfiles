#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum(0);
    for(auto&x : nums)  sum+=x;
    if(sum%2) return false;
    int target = sum/2;
    bool dp[n][target+1]; memset(dp,0,sizeof(dp));
    if(nums[0]<=target)  dp[0][nums[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            dp[i][j] = dp[i-1][j];
            if(nums[i]==j){
                dp[i][j] = true;
                continue;
            }
            if(nums[i]<j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
        }
    }
    return dp[n-1][target];
}