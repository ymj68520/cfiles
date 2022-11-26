#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int integerBreak(int n) {
    if(n<2) return 0;   // 这里的n>=2 可删
    int dp[n+1];
    for(int i=2;i<=n;i++){
        dp[i] = i-1;    // i = 1+(i-1)即最小为i-1
        for(int j=1;j<i-1;j++){
            int t = i-j;
            dp[i] = max(dp[i],max(j*t,j*dp[t]));
        }
    }
    return dp[n];
}
int main(){
    cout << integerBreak(10) << endl;
    return 0;
}