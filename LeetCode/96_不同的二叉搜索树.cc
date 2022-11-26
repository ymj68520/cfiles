#include <iostream>
#include <cstring>
using namespace std;

/*
n 个节点存在二叉排序树的个数是 G (n)，令 f(i) 为以 i 为根的二叉搜索树的个数，则
    G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)【1】
当 i 为根节点时，其左子树节点个数为 i-1 个，右子树节点为 n-i，则
    f(i) = G(i-1)*G(n-i)【2】
将公式2带入公式1得到卡特兰数计算公式：
    G(n)=G(0)∗G(n−1)+G(1)∗(n−2)+...+G(n−1)∗G(0)
*/
class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        memset(dp,0,sizeof(dp));
        return generator(n);
    }
    int generator(int n){
        if(n==0 || n==1) return 1;
        if(dp[n]>0) return dp[n];
        for(int i=0;i<n;i++){
            dp[n] += generator(i) * generator(n-i-1);
        }
        return dp[n];
    }
};

int main(){
    Solution sl;
    cout << sl.numTrees(3) << endl;

    return 0;
}