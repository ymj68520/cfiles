#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    double soupServings(int n) {
        n = (n+24) / 25;
        if(n>179)   return 1.000000;

        double dp[n+10][n+10];
        dp[0][0] = 0.5;
        for(int i=1;i<=n;++i)    dp[0][i] = 1.0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // 情况1：只分配100（100/25）A
                double a = dp[max(i-4,0)][j];
                // 情况2：分配75 A 和 25 B
                double b = dp[max(i-3,0)][max(j-1,0)];
                // 情况3：分配50 A 和 50 B
                double c = dp[max(i-2,0)][max(j-2,0)];
                // 情况3：分配25 A 和 75 B
                double d = dp[max(i-1,0)][max(j-3,0)];
                // 情况1234等概率，则计算均值。
                dp[i][j] = (a+b+c+d)/4;
            }
        }

        return dp[n][n];
    }
};

int main(){
    Solution sol;

    cout << sol.soupServings(450) << endl;

    return 0;
}