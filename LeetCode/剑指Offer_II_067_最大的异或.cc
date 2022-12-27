#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// TLE
class Solution1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, n=nums.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                ans = max(ans,nums[i]^nums[j]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

    }
};