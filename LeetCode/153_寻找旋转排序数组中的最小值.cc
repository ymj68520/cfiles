#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=-1, r=nums.size()-1;
        while(l+1 < r){
            int m = l + ((r-l)>>1) ;
            if(nums[m] < nums.back())   r = m;
            else l = m;
        }
        return nums[r];
    }
};