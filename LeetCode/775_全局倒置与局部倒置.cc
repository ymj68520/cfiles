#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int glo=0,part=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])   part++;
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]) glo++;
            }
        }
        return glo == part;
    }
    bool isIdealPermutation2(vector<int>& nums) {
        int preMax=0;
        for(int i=2;i<nums.size();++i){
            preMax = max(preMax, nums[i-2]);
            if(preMax > nums[i])    return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,0,2};
    Solution sol;
    cout << sol.isIdealPermutation(nums) << endl;
    cout << sol.isIdealPermutation2(nums)<< endl;

    return 0;
}
