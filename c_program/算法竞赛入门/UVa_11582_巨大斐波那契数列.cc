#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef unsigned long long ll;
using namespace std;
const int maxn=1000+10;

ll a,b;
int f[maxn*maxn],n,M;

int pow(ll a,ll p,int Mod){
    if(p==0)    return 1;
    int x = pow(a,p/2,Mod);
    ll ans = x * x % Mod;
    if(p % 2 == 1)  ans = ans * a % Mod;
    return (int)ans;
}

inline void solve()
{
    cin>>a>>b>>n;
    if(n==1||!a){printf("0\n");return ;}
    f[1]=1,f[2]=1;
    for(int i=3;i<=n*n+10;i++)  // 计算n^2个
    {
        f[i]=f[i-1]+f[i-2];f[i]%=n;
        if(f[i]==f[2]&&f[i-1]==f[1]) {M=i-2;break;}
    }
    int k=pow(a%M,b,M);
    printf("%d\n",f[k]);
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}