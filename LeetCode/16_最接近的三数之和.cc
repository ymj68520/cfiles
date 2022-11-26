#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-2;i++){
        int p(i+1),q(nums.size()-1);
        while(p!=q){
            int temp = nums[i] + nums[p] + nums[q];
            if(abs(target - ans) > abs(temp - target))
                ans = temp;
            if(temp > target){
                q--;
                while(p!=q && nums[q]==nums[q+1])   q--;
            }
            else{
                p++;
                while(p!=q && nums[p]==nums[p-1])   p++;
            }
        }
        while(i<nums.size()-2 && nums[i]==nums[i+1]) i++;        
    }
    return ans;
}

int main(){
    // [4,0,5,-5,3,3,0,-4,-5]
    // -2
    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    cout << threeSumClosest(nums,-2) << endl;

    return 0;
}