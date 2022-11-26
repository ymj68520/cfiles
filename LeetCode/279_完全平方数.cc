#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int numSquares(int n) {
    if(n<2) return 1;
    int dp[n+1];memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        int mini=INT32_MAX;
        for(int j=1;j*j<=i;j++){
            mini = min(mini,dp[i-j*j]);
        }
        dp[i] = mini+1;
    }
    return dp[n];
}
int main(){
    cout << numSquares(12) << endl;
    return 0;
}