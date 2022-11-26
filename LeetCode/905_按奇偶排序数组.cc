#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int p(0);
        // while(p<q){
        //     if(nums[p]%2)
        //         swap(nums[p],nums[q--]);
        //     p++;
        // }
        for(int i=0;i<n;++i) if(nums[i]%2 == 0)
                swap(nums[i],nums[p++]);

        return nums;
    }
};

int main(){
    vector<int> nums = {1,3,4};
    Solution sol;

    auto ans = sol.sortArrayByParity(nums);

    for(auto &s : ans)  cout << s;
    cout<< endl;

    return 0;
}