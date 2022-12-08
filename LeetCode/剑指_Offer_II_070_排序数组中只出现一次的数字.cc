#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=-1,r=n-1,mid=0;
        while(l<r){
            mid = l + ((r-l)>>1);
            if(nums[mid] == nums[mid+1]){
                if(mid%2){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            else if(nums[mid-1] == nums[mid]){
                if(mid %2){
                    l = mid;
                }
                else
                    r = mid;
            }
            else{
                return nums[mid];
            }
        }
        return nums[r];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = ((high - low)>>1) + low;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main(){
    vector<int> nums = {1,2,2,3,3,4,4,5,5};
    Solution sol;
    cout << sol.singleNonDuplicate(nums) << endl;

    return 0;
}