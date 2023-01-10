#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

class Solution1 {
public:
    string crackSafe(int n, int k) {
        int k_n1 = pow(k,n-1),k_n = k_n1 * k;
        int num[k_n1];
        fill(num,num+k_n1,k-1);
        string s(k_n+n-1,'0');
        for(int i=n-1,node=0;i<s.size();++i){
            s[i] = num[node]-- + '0';
            node = node*k - (s[i-n+1]-'0') * k_n1 + num[node] + 1;
        }
        return s;
    }
};

class Solution {
public:
    int n, k, mod;
    string ans;
    set<int> vis;  //判断每条边是否访问过
    string crackSafe(int N, int K) {
        n = N; k = K; mod = pow(10, n - 1); 
        ans.clear();vis.clear();
        dfs(0); //从0点出发
        ans += string(n - 1, '0'); //添加最开始的0的前缀
        return ans;
    }
    void dfs(int u) {
        for (int i = 0; i < k; i++) { //对于每个点循环k条边即可
            int v = u * 10 + i; //即边的编号
            if (vis.count(v)) continue; 
            vis.insert(v);    //标记该边已经访问 
            dfs(v % mod); //去掉第一位为结点编号 
            ans += (i+'0'); //添加最后一个数字
        }
    }
};