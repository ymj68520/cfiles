#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    //dp[i]表示截止到i，价格的最低点是多少   dp[i]=min(dp[i-1],nums[i])
    int size = prices.size();
    int dp[size];memset(dp,-1,sizeof(dp));dp[0]=prices[0];
    int tmax=0,rmax=0;
    for(int i=1;i<size;i++){
        dp[i] = min(dp[i-1],prices[i]);
        tmax = prices[i] - dp[i];
        rmax = max(tmax,rmax);
    }
    return rmax;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;

    return 0;
}