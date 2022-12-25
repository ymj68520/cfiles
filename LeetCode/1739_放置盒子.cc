#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int minimumBoxes(int n){
        long m = 1;
        while(1)
            if ( m * (m + 1) * (m + 2) / 6 <= n) ++ m;
            else return m * (m - 1) / 2 + (sqrt((8 * (n - (m * m * m - m) / 6) + 1)) + 0.9999) / 2;
    }
};

class Solution {
public:
    int minimumBoxes(int n) {
        int ans = 0, max_n = 0;
        for (int i = 1; max_n + ans + i <= n; ++i) {
            ans += i;
            max_n += ans;
        }
        for (int j = 1; max_n < n; ++j) {
            ++ans;
            max_n += j;
        }
        return ans;
    }
};
