#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1002];
int _ = []{
    dp[0] = dp[1] = 0;
    for(int i=2; i<=1000; ++i){
        int t = i, sum=0;
        while(t>0)  sum+=t%10,t/=10;
        if(sum & 1) dp[i] = dp[i-1];
        else    dp[i] = dp[i-1] + 1;
    }
    return 0;
}();

class Solution {
public:
    int countEven(int num) {
        return dp[num-1];
    }
};