#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int getMoneyAmount(int n) {
    if(n == 1)  return 0;
    int dp[n+1][n+1];memset(dp,0,sizeof(dp));
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            int ans = INT_MAX;
            for(int k=j+1;k<i;k++)
                ans = min(ans, k+max(dp[j][k-1],dp[k+1][i]));
            ans = min(ans,j+dp[j+1][i]);
            ans = min(ans,i+dp[j][i-1]);
            dp[j][i] = ans;
        }
    }
    return dp[1][n];
}

int main(){
    cout << getMoneyAmount(2) << endl;

    return 0;
}