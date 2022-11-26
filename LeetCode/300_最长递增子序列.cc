#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n==0)    return 0;
    int maxl=0;
    int dp[n];
    for(int i=0;i<n;i++)    dp[i] = 1;
    // 以j开始i结束的最长子串
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]) dp[i] = max(dp[i],dp[j]+1);
        }
        maxl = max(maxl,dp[i]);
    }
    return maxl;
}
int main(){
    vector<int> nums = {3,2,1};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}