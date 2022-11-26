#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int> > grid(n+10,vector<int>(n+10,1));
        for(auto const & m : mines){
            grid[m[0]+1][m[1]+1] = 0;
        }
        int a[n+10][n+10];memset(a,0,sizeof(a));
        int b[n+10][n+10];memset(b,0,sizeof(b));
        int c[n+10][n+10];memset(c,0,sizeof(c));
        int d[n+10][n+10];memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][j] == 1){
                    a[i][j] = a[i-1][j]+1;
                    b[i][j] = b[i][j-1]+1;
                }
                if(grid[n+1-i][n+1-j] == 1){
                    c[n+1-i][n+1-j] = c[n+2-i][n+1-j]+1;
                    d[n+1-i][n+1-j] = d[n+1-i][n+2-j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = max(ans,min(min(a[i][j],b[i][j]),min(c[i][j],d[i][j])));
            }
        }
        return ans;
    }
};