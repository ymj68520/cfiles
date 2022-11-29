#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j])  dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1);
            }
        }
        return dp[0][n-1];
    }
};
int main(){
    string s = "leetcode";
    Solution sol;

    cout << sol.minInsertions(s) << endl;

    return 0;
}