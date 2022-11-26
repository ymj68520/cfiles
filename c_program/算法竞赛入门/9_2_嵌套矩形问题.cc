#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

struct rect{
    int l;
    int w;
};
rect a[MAX];
int G[MAX][MAX];
int d[MAX];
int T,n;
int dp(int i){
    if(d[i])    return d[i];
    d[i] = 1;
    for(int j=1;j<=n;j++)
        if(G[i][j]) d[i] = max(d[i],dp(j)+1);
    return d[i];
}  
void dispaly(int i){
    cout << i << " ";
    for(int j=1;j<=n;j++){
        if(G[i][j] && d[i]==d[j]+1){
            dispaly(j);return;
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(G,0,sizeof(G));
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].l,&a[i].w);
            for(int j=1;j<i;j++)
                if(a[j].l < a[i].l && a[j].w < a[i].w
                ||(a[j].w < a[i].l && a[j].l < a[i].w))
                    G[j][i] = 1;
                else if(a[j].l > a[i].l && a[j].w > a[i].w
                     ||(a[j].w > a[i].l && a[j].l > a[i].w))
                    G[i][j] = 1;
        }
        int max_i = 0;
        for(int i=1;i<=n;i++) if(dp(max_i) < dp(i)) max_i = i;
        cout <<d[max_i] <<endl;
        dispaly(max_i);   
    }
    return 0;
}