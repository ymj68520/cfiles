#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return n;
    int dp[n][2];memset(dp,0,sizeof(dp));
    dp[0][0] = 1;dp[0][1] = 1;
    int manl=0;
    
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0] + 1;
        }
        else if(nums[i]<nums[i-1]){
            dp[i][0] = dp[i-1][1] + 1;
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        } 
    }

    return max(dp[n-1][0],dp[n-1][1]);
}

int main(){
    vector<int> nums = {1,7,4,9,2,5};
    cout << wiggleMaxLength(nums) << endl;

    return 0;
}