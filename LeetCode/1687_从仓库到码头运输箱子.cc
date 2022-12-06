#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// 35/39 个通过测试用例，超出时间限制
class Solution_t {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long ws[n + 1];
        int cs[n];
        ws[0] = cs[0] = 0;
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
        }
        int f[n + 1];
        
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxBoxes); j < i; ++j) {
                if (ws[i] - ws[j] <= maxWeight) {
                    f[i] = min(f[i], f[j] + cs[i - 1] - cs[j] + 2);
                }
            }
        }
        return f[n];
    }
};

class Solution_tt {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long ws[n + 1];
        int f[n + 1];
        int cs[n];
        ws[0] = cs[0] = f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
        }
        deque<int> q{{0}};
        for (int i = 1; i <= n; ++i) {
            while (!q.empty() && (i - q.front() > maxBoxes || ws[i] - ws[q.front()] > maxWeight)) q.pop_front();
            if (!q.empty()) f[i] = cs[i - 1] + f[q.front()] - cs[q.front()] + 2;
            if (i < n) {
                while (!q.empty() && f[q.back()] - cs[q.back()] >= f[i] - cs[i]) q.pop_back();
                q.push_back(i);
            }
        }
        return f[n];
    }
};

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        int j = 0;
        int count = 2;
        int w = boxes[0][1];
        vector<int> f(n + 1);
        f[1] = 2;
        for (int i = 1; i < n; ++i) {
            if (boxes[i][0] != boxes[i - 1][0]) {
                count++;
            }
            w += boxes[i][1];
            while (i - j + 1 > maxBoxes || w > maxWeight || f[j] == f[j + 1]) {
                w -= boxes[j][1];
                ++j;
                if (boxes[j][0] != boxes[j - 1][0]) {
                    count--;
                }
            }
            f[i + 1] = f[j] + count;
        }
        return f[n];
    }
};