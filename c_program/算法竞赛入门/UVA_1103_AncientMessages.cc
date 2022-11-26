/*
5 15
fff00fff000f0f0
f0f00f0f000f0f0
fff0fffff0fffff
f0f000f00000f00
fff000f00000f00

已知bug：边界仍然被遍历为-1
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200 + 10;
int pic[maxn][maxn];
int H,W,C;
int count_t;    // namepace std 中含有count变量。
int ans[8];
char ANS[6]= {'A','D','J','K','S','W'};
int change[][4] = {
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1},
    {1,0,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {1,1,0,1},
    {1,1,1,0},
    {1,1,1,1},
};
void input(){
    C = W * 4;  // 总宽
    getchar();  // 读取回车
    memset(ans,0,sizeof(ans));
    memset(pic,0,sizeof(pic));
    for(int i=1;i<=H;i++){
        int L = 1;
        for(int j=1;j<=W;j++){
            char ch = getchar();
            if(ch>='0' && ch <= '9')
                for(int k=0;k<4;k++)   pic[i][L++] = change[ch-'0'][k];
            else
                for(int k=0;k<4;k++)   pic[i][L++] = change[ch-'a'+10][k];
        }
        getchar();// 行末回车
    }
}
bool check(int x,int y){    // 判断x，y点是否出界
    if((x>=0&&x<=H+1)&&(y>=0&&y<=C+1))
        return true;
    return false;
}
void dfs(int x,int y){
    if( !check(x,y) || pic[x][y])   // 找边界，边界内所有块标记为-1
        return;
    pic[x][y] = -1;
    /*
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            dfs(x+i,y+j);
    */
   dfs(x-1,y);dfs(x,y-1);dfs(x+1,y);dfs(x,y+1);
}
void DFS(int x,int y){
    if(!check(x,y) || pic[x][y]==-1)    // 出界或者该点已经走过
        return;
    if(pic[x][y]==0){
        count_t++;
        dfs(x,y);
        return;
    }
    pic[x][y] = -1;
    /*
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            DFS(x+i,y+j);
    */
   DFS(x-1,y);DFS(x+1,y);DFS(x,y-1);DFS(x,y+1);
}
int main(){
    int t=1;
    while(cin>>H>>W && H && W){
        input();
        /*
        for(int i=1;i<=H;i++){
            for(int j=1;j<=C;j++)
                cout << pic[i][j];
            putchar('\n');
        }
        */
        dfs(0,0);
        /*
        for(int i=0;i<=H+1;i++){
            for(int j=0;j<=C+1;j++)
                cout << pic[i][j];
            putchar('\n');
        }
        */
        cout << "Case" << t++ << ":";
    for(int i=1;i<=H;i++){
        for(int j=1;j<=C;j++){
            count_t=0;
            DFS(i,j);
            switch(count_t){
                case 0: ans[5]++;break;// W
                case 1: ans[0]++;break;// A
                case 2: ans[3]++;break;// K
                case 3: ans[2]++;break;// J
                case 4: ans[4]++;break;// S
                case 5: ans[1]++;break;// D
            }
        }
    }
    /*
    for(int i=0;i<=H+1;i++){
            for(int j=0;j<=C+1;j++)
                cout << pic[i][j];
            putchar('\n');
        }
    */
    for(int i=0;i<=6;i++)
        while(ans[i]--)     cout << ANS[i];
    cout << '\n';
    }
    return 0;
}