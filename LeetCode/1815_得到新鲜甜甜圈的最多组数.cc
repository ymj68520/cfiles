#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize, 0);
        for(int i : groups) cnt[i % batchSize]++;

        int all = 1;
        for(int i = 1; i < batchSize; ++i) all *= cnt[i] + 1;

        vector<int> f(all);
        f[0] = 0;
        for(int state = 1; state < all; ++state) {
            int sum = batchSize; // 这里令 sum = batchSize 后续避免负数取模问题
            for(int num = 1, t = state; num < batchSize; t /= cnt[num] + 1, ++num)
                sum += num * (t % (cnt[num] + 1));
            for(int num = 1, t = state, w = 1; num < batchSize; 
                t /= cnt[num] + 1, w *= cnt[num] + 1, ++num)
                if(t % (cnt[num] + 1))
                    f[state] = max(f[state], f[state - w] + ((sum - num) % batchSize == 0));
        }

        return f[all-1] + cnt[0];
    }
};