// 输入n(n<=100000)个单词，是否可以把所有这些单词排成一个序列，
// 使得每个单词的第一个字母和上一个单词的最后一个字母相同。
// 每个单词最多包含1000个小写字母。输入可以重复。

// 拓扑排序

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1000 + 10;

int G[maxn][maxn];
int vis[maxn];
int topo[maxn];
int n,t;

void input(){
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++){
        char temp[1000+10];
        scanf("%s",temp);
        G[temp[0]-'a'][temp[strlen(temp)-1]-'a'] = 1;
    }
}

bool dfs(int u){
    vis[u] = -1;  // 访问标志
    for(int v=0;v<n;v++)
        if(G[u][v]){
            if(vis[v]<0)  return false;
            else if(!G[u][v] && !dfs(v))    return false;
        }
    vis[u] = 1;
    topo[--t] = u;
    return true;
}


bool toposort(){
    t = n;
    memset(vis,0,sizeof(vis));
    for(int u=0; u<n; u++)  if(!vis[u])
        if(!dfs(u)) return false;
    return true;
}

int main(){
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    memset(topo,0,sizeof(topo));
    input();
    if(toposort())
        puts("Yes");
    else
        puts("No");

    return 0;
}
