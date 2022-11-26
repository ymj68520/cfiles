#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>


/*
    0. 上下都没有
    1. 只有上方
    2. 只有下方
    3. 上下都有
*/
using namespace std;
class Solution {
public:
    const int MOD = 1e9+7;
    int numTilings(int n) {
        long long dp[n+1][4];memset(dp,0,sizeof(dp));
        dp[0][3] = 1;
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][3];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
            dp[i][3] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]) % MOD;
        }
        return dp[n][3];
    }
};

int main(){
    Solution sol;
    cout << sol.numTilings(10) << endl;

    return 0;
}


/*
class Solution {
    int mod=(int)1e9+7,matrix[][]={{0,1,1,1},{0,0,1,1},{0,1,0,1},{1,0,0,1}}; 
    public int numTilings(int n) {
        long ans[][]=new long[n][4];
        ans[0]=new long[]{1,0,0,1};
        for(int i=1;i<n;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){ans[i][j]+=ans[i-1][k]*matrix[k][j];}
                ans[i][j]%=mod;
            }
        }
        return (int)ans[n-1][3];
    }
}*/