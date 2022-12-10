#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &x : cuboids)  sort(x.begin(),x.end());
        sort(cuboids.begin(),cuboids.end());
        int n = cuboids.size();
        int dp[n];
        for(int i=0;i<n;++i){
            dp[i] = 0;
            for(int j=0;j<i;++j){
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
        }
        return *max_element(dp,dp+n);
    }
};

int main(){

}