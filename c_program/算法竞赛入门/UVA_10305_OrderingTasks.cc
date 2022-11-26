/*
    假设有n变量，和m个二元组（u、v），分别表示变量u小于v。
    那么，所有变量从小到大排列起来是什么样子？

    分析：
        将每个变量看做一个点，小于关系看成有向边，则得到了一个有向图。
        这样，我们的任务实际上是把每一个图的所有节点排序，
        使得每一条有向边（u、v）对应的u都排在v的前面。
    上述问题即为拓扑排序。

    如果图中存在有向环，则不存在拓扑排序。
    拓扑有序图称为有向无环图。

    可以借助DFS完成拓扑排序：在访问完一个结点之后把它加到当前拓扑排序的首部。
*/
#include <iostream>
#include <cstring>
const int maxn = 1000 + 10;
int n,m,G[maxn][maxn];
int c[maxn];
int topo[maxn],t;
using namespace std;
bool dfs(int u){
    c[u] = -1;  // 访问标志
    for(int v=0;v<n;v++)    // 依次遍历所有可能存在的边
        if(G[u][v]){    // 存在边u-->v
            if(c[v] < 0) return false;  // 已经被访问过则存在有向环
            else if(!c[v] && !dfs(v))   return false;   // 此节点没有被访问但是其dfs结果有环
        }
    c[u] = 1;   // 确认此节点不存在环则置为1
    topo[--t] = u;  // 入栈
    return true;
}
bool toposort(){
    t = n;
    memset(c,0,sizeof(c));
    for(int u=0; u<n; u++)  if(!c[u])
        if(!dfs(u)) return false;
    return true;
}

int main(){
    memset(G,0,sizeof(G));
    memset(topo,0,sizeof(topo));
    scanf("%d %d",&n,&m);getchar();
    for(int i=0;i<m;i++){
        char temp[6];
        scanf("%s%*c",temp);
        printf("%d`th %s: %d, %d\n",i,temp,temp[1]-48,temp[3]-48);
        G[temp[1]-48][temp[3]-48] = 1;
    }
    if(toposort())
        printf("topo!");
    else
        printf("No!");

    return 0;
}