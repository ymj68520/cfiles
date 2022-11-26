#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cctype>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    const vector<int> dirs = {-1,0,1,0,-1};
    const int MAXN = 35;
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int k=0;
        int start_i(0),start_j(0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char c = grid[i][j];
                if(islower(c)) ++k;
                else if(c == '@') start_i=i,start_j=j;
            }
        }
        queue<tuple<int,int,int> > q;
        q.push(tuple<int,int,int>{start_i,start_j,0});
        int ans=0;
        int vis[MAXN][MAXN][1<<k];memset(vis,0,sizeof(vis));
        vis[start_i][start_j][0] = 1;
        while(!q.empty()){
            for(int t=q.size();t;--t){
                auto [i,j,state] = q.front();
                q.pop();
                if(state == (1<<k)-1)   return ans;
                for(int d=0;d<4;d++){
                    int x = i+dirs[d], y = j+dirs[d+1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        char c = grid[x][y];
                        if(c=='#' || (isupper(c) && ((state >> (c - 'A')) & 1) == 0)) continue;
                        int next = state;
                        if(islower(c))  next |= 1 << (c-'a');
                        if(!vis[x][y][next]){
                            vis[x][y][next] = 1;
                            q.push({x,y,next});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

int main(){
    vector<string> grid = {"@.a.#","###.#","b.A.B"};
    Solution sol;
    cout << sol.shortestPathAllKeys(grid) << endl;


    return 0;
}