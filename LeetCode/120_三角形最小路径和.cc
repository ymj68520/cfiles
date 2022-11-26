#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int dp[n][n];memset(dp,0,sizeof(dp));
    dp[0][0] = triangle[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+triangle[i][0];
        dp[i][i] = dp[i-1][i-1]+triangle[i][i];
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
        }
    }
    int minpath=__INT32_MAX__;
    for(auto x:dp[n-1]) minpath = min(x,minpath);
    return minpath;
}
int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle) << endl;

    return 0;
}