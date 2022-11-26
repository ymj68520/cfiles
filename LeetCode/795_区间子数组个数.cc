#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int numMax = INT_MIN;
            for(int j=i;j<n;j++){
                numMax = max(numMax,nums[j]);
                if(numMax > right) break;
                if(numMax < left)   continue;
                cnt++;
            }
        }

        return cnt;
    }
    int numSubarrayBoundedMax1(vector<int>& nums, int left, int right){
        int n = nums.size(), ans = 0, i0 = -1, i1 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) i0 = i;
            if (nums[i] >= left) i1 = i;
            ans += i1 - i0;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {73,55,36,5,55,14,9,7,72,52};
    cout << sol.numSubarrayBoundedMax(nums,32,36) << endl;
    cout << sol.numSubarrayBoundedMax1(nums,32,36) << endl;

    return 0;
}