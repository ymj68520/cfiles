#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
    static const int MAXN = 1000;

    int n, m;
    // 按上右下左的顺序存储方向，方便旋转
    short dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

    // 把小球的坐标和方向压缩成 int
    int gao(int i, int j, int k) {
        return i * m * 4 + j * 4 + k;
    }

    // 把 int 解压成坐标和方向
    void ungao(int p, int &i ,int &j ,int &k) {
        i = p / (m * 4);
        j = p / 4 % m;
        k = p % 4;
    }

public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        n = plate.size(); m = plate[0].size();
        static int dis[MAXN][MAXN][4];
        for (int i = 0;i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 4; k++) dis[i][j][k] = -1;

        static int q[MAXN * MAXN * 4 + 10];
        int head = 0, tail = 0;
        // 从 O 开始搜索
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (plate[i][j] == 'O')
            for (int k = 0; k < 4; k++) q[tail++] = gao(i, j, k), dis[i][j][k] = 0;
        while (head < tail) {
            int p = q[head++];
            int i, j, k; ungao(p, i, j, k);
            // 往当前方向移动一步
            int ii = i + dir[k][0], jj = j + dir[k][1], kk = k;
            // 小球掉出棋盘
            if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
            // 遇到 W，因为是倒过来搜索所以要顺时针旋转
            if (plate[ii][jj] == 'W') kk = (kk + 1) % 4;
            // 遇到 E，因为是倒过来搜索所以要逆时针旋转
            else if (plate[ii][jj] == 'E') kk = (kk + 3) % 4;
            if (dis[ii][jj][kk] >= 0) continue;
            q[tail++] = gao(ii, jj, kk);
            dis[ii][jj][kk] = dis[i][j][k] + 1;
        }
        
        // 统计答案，注意题目要求只能从边缘的 . 格子进入，而且方向还要垂直于边缘
        vector<vector<int>> ans;
        for (int i = 1; i + 1 < n; i++) 
            if (plate[i][0] == '.' && dis[i][0][3] >= 0 && dis[i][0][3] <= num) ans.push_back({i, 0});
        for (int i = 1; i + 1 < n; i++) 
            if (plate[i][m - 1] == '.' && dis[i][m - 1][1] >= 0 && dis[i][m - 1][1] <= num) ans.push_back({i, m - 1});
        for (int j = 1; j + 1 < m; j++) 
            if (plate[0][j] == '.' && dis[0][j][0] >= 0 && dis[0][j][0] <= num) ans.push_back({0, j});
        for (int j = 1; j + 1 < m; j++) 
            if (plate[n - 1][j] == '.' && dis[n - 1][j][2] >= 0 && dis[n - 1][j][2] <= num) ans.push_back({n - 1, j});
        
        return ans;
    }
};

class Solution {
public:
    vector<string> p;
    bool dfs(int x,int y,int tox,int toy,int num){
        if(x<0||y<0||x>=p.size()||y>=p[0].size()) return 0;
        if(p[x][y]=='O') return 1;
        if(num==0) return 0;
        if(p[x][y]=='W'){
            int t=-1*toy;
            toy=tox;
            tox=t;
        }
        else if(p[x][y]=='E'){
            int t=-1*tox;
            tox=toy;
            toy=t;
        }
        return dfs(x+tox,y+toy,tox,toy,num-1);
    }
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        p=plate;
        vector<vector<int>> ans;
        int n=plate.size(),m=plate[0].size();
        for(int i=1;i<n-1;i++){
            if(plate[i][0]=='.'){
                if(dfs(i,0,0,1,num)) ans.push_back({i,0});
            }
            if(plate[i][m-1]=='.'){
                if(dfs(i,m-1,0,-1,num)) ans.push_back({i,m-1});
            }
        }
        for(int j=1;j<m-1;j++){
            if(plate[0][j]=='.'){
                if(dfs(0,j,1,0,num)) ans.push_back({0,j});
            }
            if(plate[n-1][j]=='.'){
                if(dfs(n-1,j,-1,0,num)) ans.push_back({n-1,j});
            }
        }
        return ans;
    }
};