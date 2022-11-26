#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
/*
[186,419,83,408]
6249
*/
// int coinChange(vector<int>& coins, int amount) {
//     if(amount==0)   return 0;
//     int n = coins.size();if(n<1) return -1;
//     sort(coins.begin(),coins.end());
//     int count=0;
//     while(amount>0 && n){
//         while(coins[n-1]<=amount){
//             amount-=coins[n-1];
//             count++;
//         }
//         n--;
//     }
//     if(amount == 0) return count;
//     else    return -1;
// }
int coinChange(vector<int>& coins, int amount){
    int n = coins.size();
    if(n==0)    return 0;
    int dp[amount+1];memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=amount;i++){
        for(auto& coin:coins){
            if(i-coin>=0 && dp[i-coin]){
                if(dp[i]==0)    dp[i] = dp[i-coin]+1;
                else    dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
    }
    return dp[amount]-1;
}

int main(){
    vector<int> coins = {186,419,83,408};
    cout << coinChange(coins,6249) << endl;
    return 0;
}