#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int uniquePaths(int m, int n) {
    // C(m+n-2)(m-1)
    int M = m+n-2;
    int N = m-1;
    int mul=1;
    for(int i=0;i<N;i++)
        mul=mul * (M-i) / (i+1);

    return mul;   
}
int uniquePaths1(int m, int n){
    int dp[m][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)    dp[i][0] = 1;
    for(int i=0;i<n;i++)    dp[0][i] = 1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
    return dp[m-1][n-1];
}

int main(){
    cout << uniquePaths(7,3) << endl << uniquePaths1(3,2) << endl;
}