#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==1 && n==1){
            if(obstacleGrid[0][0] == 1) return 0;
            else return 1;
        }
        int dp[m][n];memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else
                while(i<n){
                    dp[0][i++] = 0;
                }
        }
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else
                while(i<m){
                    dp[i++][0] = 0;
                }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> ob = {{1},{0},{0}};
    cout << sol.uniquePathsWithObstacles(ob) << endl;

    return 0;
}