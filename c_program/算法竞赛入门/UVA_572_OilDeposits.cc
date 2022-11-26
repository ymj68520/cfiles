/*
    输入m行n列的字符矩阵，统计‘@’字符组成多少个八连块（相邻【行列相邻或者对角线方向相邻】的八个？）
*/
#include <iostream>
#include <cstring>
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int r, int c, int id){
    if(r<0 || r>=m || c<0 || c>=n) return;  // 出界
    if(idx[r][c] > 0 || pic[r][c]!='@') return;     // 非“@”
    idx[r][c] = id; // 连通分量标号
    for(int dr = -1;dr<=1;dr++)
        for(int dc = -1;dc<=1;dc++)
            if(dr!=0 || dc !=0) dfs(r+dr,c+dc,id);
}

int main(){
    while(scanf("%d%d",&m,&n)==2 && m && n){
        for(int i=0;i<m;i++) scanf("%s",pic[i]);
        memset(idx,0,sizeof(idx));
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(idx[i][j]==0 && pic[i][j]=='@') dfs(i,j,++cnt);
        printf("%d\n",cnt);
    }
    return 0;
}