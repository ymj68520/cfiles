#include <bits/stdc++.h>
// using namespace std;
const int MAX = INT32_MAX;
// 1. 欧几里得算法（辗转相除法）
int gcd(int a, int b){
    return b==0 ? a: gcd(b,a%b);
}
// 2. 拓展的欧几里得算法
void t_gcd(int a, int b, int &d, int &x, int &y){
    if(!b){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        t_gcd(b,a%b,d,y,x); // ***
        y -= x*(a%b);       // *****
    }
}
// 3. Eratosthenes筛法
int vis_era[MAX] = {0};   // 表示没有被删除元素
void Eratosthenes1(int n){
    for(int i=2;i<n;i++)
        for(int j=2*i;j<=n;j+=i)
            vis_era[j] = 1; // 表示j这个数被剔除
}
void Eratosthenes2(int n){
    int m = std::sqrt(n+0.5);    // 0.5为欧拉常数
    int i,j;
    for(i=2; i<=m; i++)   if(!vis_era[i])
        for(j=i*i; j<=n; j+=i)    vis_era[j] = 1;
}
// 4. 同余和模
// （1）大整数取模
void bigmodn(char *n, int m){
    int len = std::strlen(n);
    int ans = 0;
    for(int i=0; i<len;i++){
        ans = (int) (((long long)ans*10 + n[i]-'0')%m);
    }
    printf("%d\n",ans);
}
// （2）幂取模 (a^n)%m
int pow_mod(int a,int n, int m){
    int ans = 1;
    for(int i=0;i<n;i++)    ans = (int)((long long) ans * n % m);
    return ans;
}
int better_pow_mod(int a, int n, int m){    // 分治法   快速幂
    if(n==0)    return 1;
    int x = better_pow_mod(a,n/2,m);
    long long ans = (long long)x *x %m;
    if(n%2 == 1)    ans = ans *a %m;
    return (int)ans;
}
// （3）同余方程的解
