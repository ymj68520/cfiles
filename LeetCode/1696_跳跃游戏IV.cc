#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
private:
    static const int N = 1e5 + 10;
    int q[N], dp[N];
    int n;
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        for(int i=1;i<n;++i){
            for(int j=max(0,i-k);j<i;++j){
                dp[i] = max(dp[i],dp[j]);
            }
            dp[i]+=nums[i];
        }
        return dp[n-1];
    }
    int maxResult3(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        priority_queue<pair<int, int> > heap;
        heap.emplace(nums[0], 0);
        for (int i = 1; i < n; ++i) {
            while (i - heap.top().second > k) {
                heap.pop();
            }
            dp[i] = heap.top().first + nums[i];
            heap.emplace(dp[i], i);
        }
        return dp[n - 1];
    }
    int maxResult4(vector<int>& nums, int k){
        n = nums.size();
        int hh = 0, tt = 0;
        dp[0] = nums[0];
        for(int i = 1; i < n; i ++){
            dp[i] = dp[q[hh]] + nums[i];
            while(hh <= tt && q[hh] <= i - k) hh ++;
            while(hh <= tt && dp[q[tt]] <= dp[i]) tt --;
            q[++ tt] = i;
        }
        return dp[n - 1];
    }
};