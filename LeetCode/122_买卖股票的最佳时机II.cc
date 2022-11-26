#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    // 贪心算法
    int size = prices.size();
    if(size < 2) return 0;
    int tmax=0;
    for(int i=0;i<size-1;i++)
        if(prices[i+1]-prices[i] > 0)   tmax += prices[i+1]-prices[i];

    return tmax;    
}
int maxProfit_dtgh(vector<int>& prices){
    const int size = prices.size();
    if(size < 2)    return 0;
    int dp[size][2];memset(dp,0,sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i=1;i<size;i++){
        dp[i][0] = max(dp[i-1][0],prices[i]+dp[i-1][1]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
    }
    return dp[size-1][0];
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl << maxProfit_dtgh(prices) << endl;

    return 0;
}