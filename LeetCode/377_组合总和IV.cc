#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    int dp[target+1];memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++)
        if(nums[j]<=i)  dp[i] = dp[i] + dp[i-nums[j]];
    }
    return dp[target];
}

int main(){
    vector<int> nums = {1,2,3};
    cout << combinationSum4(nums,4) << endl;

    return 0;
}