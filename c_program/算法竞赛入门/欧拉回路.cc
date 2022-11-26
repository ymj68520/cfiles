// 如果一个无向图是连通的，且最多只有两个奇点，则一定存在欧拉回路。
// 奇点分别为起点和终点。
// 如果奇点不存在，则可以从任意节点出发，最终一定会回到该点，此过程路径节点也称欧拉回路。

#include <iostream>
using namespace std;
const int maxn = 1000+10;
int G[maxn][maxn];
int vis[maxn][maxn];
int n,u,v;
void euler(int u){
    for(int v=0;v<n;v++)
        if(G[u][v] && !vis[u][v]){
            vis[u][v] = vis[v][u] = 1;   // 无向图
            euler(v);
            printf("%d %d\n",u,v);
        }
}
// 上述函数打印的结果是逆序的（递归），如果需要真正的路径则需要栈来存储。