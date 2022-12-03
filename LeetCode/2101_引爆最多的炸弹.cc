#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    long dis(int x1, int y1, int x2, int y2) {
        return (long)(x1 - y1) * (x1 - y1) + 
               (long)(x2 - y2) * (x2 - y2);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> edges(n);

        /* 根据能否引爆旁边炸弹, 建立邻接表 */
        for (int i = 0; i < n; ++i) {
            auto &x = bombs[i];
            for (int j = 0; j < n; ++j) {
                auto &y = bombs[j];
                if (dis(x[0], y[0], x[1], y[1]) <= (long)x[2] * x[2]) { /* 在爆炸范围 */
                    edges[i].push_back(j);
                }
            }
        }

        int ans = 0;
        /* 从每个顶点开始, BFS搜索, 找到最大的引爆数量 */
        for (int i = 0; i < n; ++i) {
            vector<bool> vis(n);
            int cnt = 0;
            vis[i] = true;
            queue<int> q;
            q.push(i);

            /* 根据邻接表, 进行BFS */
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cnt++;
                for (auto &v : edges[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            ans = max(ans, cnt); /* 更新最大引爆数量 */
        }
        return ans;
    }
};

int main(){
    vector<vector<int> > b = {{2,1,3},{6,1,4}};
    Solution sol;

    cout << sol.maximumDetonation(b) << endl;

    return 0;
}