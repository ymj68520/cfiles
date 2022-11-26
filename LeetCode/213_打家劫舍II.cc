#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int rob(vector<int>& nums) {
    const int n = nums.size();
    if(n==0)    return 0;
    int dp[n+1][2];memset(dp,0,sizeof(dp));
    dp[0][0]=dp[1][1]=0;dp[1][0]=nums[0];dp[2][1]=nums[1];
    for(int i=2;i<n;i++)
        dp[i][0] = max(dp[i-1][0],dp[i-2][0]+nums[i-1]);
    for(int i=3;i<n+1;i++)
        dp[i][1] = max(dp[i-1][1],dp[i-2][1]+nums[i-1]);
    return max(dp[n-1][0],dp[n][1]);    
}

int main(){
    vector<int> nums = {2,3,2};
    cout << rob(nums) << endl;

    return 0;
}