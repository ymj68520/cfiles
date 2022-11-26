#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int change(int amount, vector<int>& coins) {
    int dp[amount+1];memset(dp,0,sizeof(dp));
    dp[0] = 1;

    for(auto coin:coins){
        for(int i=coin;i<=amount;i++){
            dp[i] = dp[i] + dp[i-coin];
        }
    }
    return dp[amount];
}

int main(){
    vector<int> nums = {1, 2, 5};
    cout << change(5,nums) << endl;

    return 0;
}