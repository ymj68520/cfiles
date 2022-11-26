#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0,sum=0,len=__INT_MAX__;
        while(right<nums.size()){
            sum += nums[right++];
            while(sum >= target){
                len = min(len,right-left);
                sum -= nums[left++]; 
            }
        }
        if(len == __INT_MAX__)  return 0;
        else    return len;
    }
};