#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size()==1 && nums[0]!=target)   return -1;
    if(target < nums[0]){
        if(target > nums[nums.size()-1])    return -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] == target)   return i;
            if(nums[i]>target && nums[i-1]<target)  return -1;
        }
    }
    else{
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==target) return i;
            if(nums[i]<target && nums[i+1]>target)  return -1;
        }
    }
}
int search2(vector<int> &nums, int target){
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        
        // 先根据 nums[0] 与 target 的关系判断目标值是在左半段还是右半段
        if (target >= nums[0]) {
            // 目标值在左半段时，若 mid 在右半段，则将 mid 索引的值改成 inf
            if (nums[mid] < nums[0]) {
                nums[mid] = INT_MAX;
            }
        } else {
            // 目标值在右半段时，若 mid 在左半段，则将 mid 索引的值改成 -inf
            if (nums[mid] >= nums[0]) {
                nums[mid] = INT_MIN;
            }
        }

        if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {1};
    int n = 1;
    cout << search2(nums,n) << endl;
    return 0;    
}