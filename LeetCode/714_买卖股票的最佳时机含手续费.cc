#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n][2];memset(dp,0,sizeof(dp));
        dp[0][1] = -prices[0]-fee;
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
};

int main(){
    vector<int> p = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution sol;

    cout << sol.maxProfit(p,fee) << endl;

    return 0;
}