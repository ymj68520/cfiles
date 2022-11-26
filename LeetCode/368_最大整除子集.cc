#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(),nums.end());
    int dp[len];for(int i=0;i<len;i++)  dp[i] = 1;
    int maxSize=1;int maxVal=1;
    for(int i=1;i<len;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]>maxSize){
            maxSize = dp[i];
            maxVal = nums[i];
        }
    }
    vector<int> ret;
    if(maxSize==1){
        ret.push_back(nums[0]);
        return ret;
    }
    for(int i=len-1;i>=0&&maxSize>0;i--){
        if(dp[i]==maxSize && maxVal%nums[i]==0){
            ret.push_back(nums[i]);
            maxVal = nums[i];
            maxSize --;
        }
    }
    return ret;
}
int main(){
    vector<int> nums = {1,2,4,8};
    vector<int> ans =  largestDivisibleSubset(nums);
    for(auto& x:ans)    cout << x << " ";
    cout << endl;

    return 0;
}