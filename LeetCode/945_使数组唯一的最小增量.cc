#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int pre = nums[i];
                nums[i] = nums[i-1]+1;
                ans += nums[i]-pre;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3,7};
    Solution sol;

    cout << sol.minIncrementForUnique(nums) << endl;
}