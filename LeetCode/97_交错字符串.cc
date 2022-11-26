#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

#define foR for
bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    if(n1+n2 != n3) return false;

    bool dp[n1+1][n2+1]; memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    foR(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            int pos = i+j-1;
            if(i>0)
                dp[i][j] |= dp[i-1][j] && (s1[i-1]==s3[pos]);
            if(j>0)
                dp[i][j] |= dp[i][j-1] && (s2[j-1]==s3[pos]);
        }
    }
    return dp[n1][n2];
}

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    cout << isInterleave(s1,s2,s3) << endl;

    return 0;
}