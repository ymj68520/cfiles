#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums.resize(nums.size()+1);
        this->nums[0] = 0;
        for(int i=1;i<=nums.size();i++){
            this->nums[i] = nums[i-1] + this->nums[i-1]; 
        }
    }
    
    int sumRange(int left, int right) {
        return nums[right+1]-nums[left];
    }
};
