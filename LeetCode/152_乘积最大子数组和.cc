#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int maxProduct(vector<int>& nums) {
    int tmax(1);int tmin(1);
    int maxnum = -__INT32_MAX__;
    for(int i=0;i<nums.size();i++){
        if(nums[i] < 0) swap(tmax,tmin);
        tmax = max(tmax*nums[i],nums[i]);
        tmin = min(tmin*nums[i],nums[i]);
        maxnum = max(maxnum,tmax);
    }
    return maxnum;
}
int main(){
    vector<int> nums = {2,0,-8,4,-1};
    cout << maxProduct(nums) << endl;
    
    return 0;
}
