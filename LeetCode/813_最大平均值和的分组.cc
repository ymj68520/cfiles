#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

class Solution {

public:
    double largestSumOfAverages1(vector<int>& nums, int k) {
        int n = nums.size();
        int s[n+1];
        vector<vector<double> > f(n,vector<double>(k+1,0.0));
        s[0] = 0;
        for(int i=0;i<n;i++)    s[i+1] = s[i] + nums[i];
        function<double(int,int)> dfs = [&](int i,int k)->double{
            if(i == n)  return 0;
            if(k == 1)  return (s[n]-s[i])*1.0 / (n-i);
            if(f[i][k])  return f[i][k];
            double ans = 0.0;
            for(int j=i;j<n;++j){
                double t = (s[j+1] - s[i])*1.0 / (j-i+1) + dfs(j+1,k-1);
                ans = max(ans,t);
            }
            return f[i][k] = ans;
        };
        return dfs(0,k);
    }
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        //初始状态为-无穷，代表可不行
        vector<vector<double>> dp(n + 5, vector<double>(K + 5, -0x3f3f3f3f));  
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= K; j++) { 
                double sum = 0;
                for (int k = i; k >= j; k--) {
                    sum += nums[k - 1];
                    dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + sum / (i - k + 1));
                } 
            } 
        }
        return dp[n][K];
    }
};

int main(){
    int k = 5;
    vector<int> nusm = {1,2,3,4,5,6,7};
    Solution sol;

    cout << sol.largestSumOfAverages(nusm,k) << endl;

    return 0;
}