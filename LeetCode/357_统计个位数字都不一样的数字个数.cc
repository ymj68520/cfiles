#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int countNumbersWithUniqueDigits(int n) {
    if(n==0)    return 1;
    int dp[n+1];memset(dp,0,sizeof(dp));
    dp[0] = 1; dp[1] = 10;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + (dp[i-1] - dp[i-2])*(10-(i-1));
    }
    return dp[n];
}
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)    return 1;
        int dp[n+1];memset(dp,0,sizeof(dp));
        dp[0] = 1; dp[1] = 10;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + (dp[i-1] - dp[i-2])*(10-(i-1));
        }
        return dp[n];
    }
};

int main(){
    for(int i=0;i<=8;i++)
        cout << i << ": " << countNumbersWithUniqueDigits(i) << endl;
    return 0;
}