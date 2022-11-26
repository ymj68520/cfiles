/*
    一根数轴,根结点是坐标index,左结点-1,右结点+1
*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10000 + 10;
int sum[maxn];

// 输入并统计一颗子树，树根水平位置为p
void build(int p){
    int v; cin >> v;
    if(v == -1) return; // 空树
    sum[p] += v;
    build(p-1);
    build(p+1);
}
bool init(){
    int v;cin >> v;
    if(v==-1)   return false;
    memset(sum,0,sizeof(sum));
    int pos = maxn/2;
    sum[pos] = v;
    build(pos-1);
    build(pos+1);
}
int main(){
    int kase = 0;
    while(init()){
        int p = 0;
        while(sum[p]==0) p++;   // 找对左边的叶子
        cout <<"Case " << ++kase<<":\n"<<sum[p++];  // 避免行末多余空格
        while(sum[p]!=0) cout << " "<< sum[p++];
        cout << "\n\n";
    }
    return 0;
}