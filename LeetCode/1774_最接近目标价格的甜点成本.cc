#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool> dp(target + 5);
        int ans = 0x3f3f3f3f;
        for (int x : baseCosts) { //判断只能选基料
            if (x > target) ans = min(ans, x);
            else dp[x] = true;
        }
        for (int x : toppingCosts) {
            for (int i = 0; i < 2; i++) { //选2次
                for (int j = target; j >= 0; j--) { 
                    if (dp[j] && j + x > target) ans = min(ans, j + x); //计算大于的情况
                    if (j > x) dp[j] = dp[j] | dp[j - x];
                }
            }
        }
        //ans-V:目前获得与target的差距 
        for (int i = 0; i <= ans - target && i <= target; i++) if (dp[target - i]) return target - i;
        return ans;
    }
};