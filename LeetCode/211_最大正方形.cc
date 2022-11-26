#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    int r = matrix.size();int c = matrix[0].size();
    if(r==0 || c==0) return 0;
    int maxboard=0;
    int dp[r][c];memset(dp,0,sizeof(dp));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j] == '1'){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]);
                    dp[i][j] = min(dp[i][j],dp[i][j-1]) + 1;
                }
                maxboard = max(maxboard,dp[i][j]);
            }
        }
    }
    return maxboard*maxboard;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},
                                   {'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}