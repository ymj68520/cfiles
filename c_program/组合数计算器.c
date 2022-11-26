#include <stdio.h>

unsigned long long fanctorial(int n){
    // 阶乘
    long long m=1;
    for(int i=1;i<=n;++i)
        m*=i;
    return m;
}
unsigned long long C(int n,int m){
    if(m<n-m)   m = n-m;
    unsigned long long ans = 1;
    for(int i=m+1;i<=n;++i) ans*=i;
    for(int i=1;i<=n-m;++i) ans/=i;
    return  ans;         //fanctorial(n)/(fanctorial(m)*fanctorial(n-m));
}

int main(){
    int n,m;
    while(~scanf("%d %d%*c",&n,&m)){
        printf("%lld\n",C(n,m));
    }
    return 0;
}