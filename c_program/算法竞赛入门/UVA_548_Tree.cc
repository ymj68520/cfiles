/*
    一颗点带权二叉树，(权值不同)
    给出中序和后序遍历
    找出一个叶子使得它到根路径上的权和最小。
    多解时叶子权越小越好
    每两行输入表示一棵树，第一行为中序，第二行为后序
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxv = 10000 + 10;
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;
// 因为各个节点权值不同因此直接用权值作为节点编号
bool read_list(int *a){
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x) a[n++] = x;
    return n > 0;
}
// 把in_order[L1...R1]和post_order[L2...R2]建成一棵树，返回树根
int build(int L1,int R1,int L2,int R2){
    if(L1>R1)   return 0;   // 空树
    int root  = post_order[R2];
    int p = L1;
    while(in_order[p]!=root) p++;
    int cnt = p-L1; // 左子树节点个数
    lch[root] = build(L1,p-1,L2,L2+cnt-1);
    rch[root] = build(p+1,R1,L2+cnt,R2-1);
    return root;
}

int best,best_sum;  // 目前为止最优解及其权值和
void dfs(int u,int sum){
    sum += u;
    if(!lch[u] && !rch[u]){
        // 叶子节点无左右孩子
        if(sum<best_sum || (sum==best_sum && u < best)){
            best = u;
            best_sum = sum;
        }
    }
    if(lch[u]) dfs(lch[u],sum);
    if(rch[u]) dfs(rch[u],sum);
}

int main(){
    while(read_list(in_order)){
        read_list(post_order);
        build(0,n-1,0,n-1);
        best_sum = __INT_MAX__;
        dfs(post_order[n-1],0);
        cout << best << "\n";
    }
    return 0;
}