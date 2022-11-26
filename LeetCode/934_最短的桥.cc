#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const static inline int dirs[] = {-1,0,1,0,-1};
void dfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int i, int j){
    grid[i][j] = -1;    // 标记已访问
    q.push(pair(i,j));
    for(int dir=0;dir<4;dir++){
        int x = i+dirs[dir];
        int y = j+dirs[dir+1];
        if(x>=0 && x<grid.size() && y>=0 && y<grid.size() && 1==grid[x][y])
            dfs(grid,q,x,y);
    }
}
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int,int> > q;

    for(int i=0,flag=1;i<n && flag;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]==1){
                dfs(grid,q,i,j);
                flag=0;
                break;
            }            
    
    int ans=0;
    while(true){
        for(int s=q.size();s>0;s--){    // 遍历当前这一次BFS的所有节点
        // while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int dir=0; dir<4; dir++){
                int x = i+dirs[dir];
                int y = j+dirs[dir+1];
                if(x>=0 && x<grid.size() && y>=0 && y<grid.size()){
                    if(grid[x][y]==1)   return ans;
                    else if(grid[x][y]==0){
                        grid[x][y] = -1;
                        q.push(pair(x,y));
                    }
                }
            }
            // ans ++;
        }
        ans ++;
    }
}
int main(){
    vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    // vector<vector<int>> grid = {{0,1},{1,0}};
    // vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
    int ans = shortestBridge(grid);
    cout << ans << endl;
    for(auto x:grid){
        for(auto y:x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}