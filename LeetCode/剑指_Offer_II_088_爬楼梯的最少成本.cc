#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()+1;
        if(n<3) return 0;
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        for(int i=2;i<n;++i)
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        return dp[n-1];
    }
};

int main(){
    vector<int> cost = {10,15,20};
    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}