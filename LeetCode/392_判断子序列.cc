#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

bool isSubsequence(string s, string t) {
    int lens = s.length();
    int lent = t.length();
    if(lent < lens) return false;
    int dp[lens+1][lent+1];memset(dp,0,sizeof(dp));
    int maxl=0;
    for(int i=1;i<=lens;i++){
        for(int j=1;j<=lent;j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i][j-1];
            maxl = max(maxl,dp[i][j]);
        }
    }
    return (maxl == lens);
}