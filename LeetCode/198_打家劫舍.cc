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
    int dp[n+1];memset(dp,0,sizeof(dp));
    dp[0]=0;dp[1]=nums[0];
    for(int i=2;i<n+1;i++)
        dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
    return dp[n];    
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;

    return 0;
}