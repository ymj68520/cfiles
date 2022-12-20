#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int __FAST_IO__ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}();

class Solution {
    public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i, m, l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            for (i = m = 0; i < nums.size(); i++) m += (nums[i] - 1) / mid;
            if (m <= maxOperations) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
