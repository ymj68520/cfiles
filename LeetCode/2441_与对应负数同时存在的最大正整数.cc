#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    unordered_set<int> ns;
public:
    int findMaxK(vector<int>& nums) {
        ns.clear();
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ns.count(-nums[i])){
                ans = max(ans,abs(nums[i]));
            }
            else{
                ns.insert(nums[i]);
            }
        }
        return ans==0 ? -1:ans;
    }
};

int main(){
    vector<int> nums = {-1,2,-3,3};
    Solution sol;

    cout << sol.findMaxK(nums) << endl;

    return 0;
}