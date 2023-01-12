#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:    
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2));
        dp[0][0] = dp[0][1] = 0;
        for(int i=1;i<=n;i++) {
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-nums[i-1]);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+nums[i-1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};

class Solution2 {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even  = nums[0],odd = 0;
        for(int i = 1; i < nums.size(); i++){
            even  =max(odd + nums[i], even);
            odd =max(even - nums[i], odd);
        }
        return even;
    }
};

class Solution1 {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long left = nums[0], right=0;
        for(int i=0;i<nums.size();++i){
            long long temp = left;
            left = max(left, right+nums[i]);    // nums[i]作为奇数下标
            right= max(right,temp -nums[i]);    // nums[i]作为偶数下标
        }
        return left;
    }
};