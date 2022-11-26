#include <stdio.h>
#include <string.h>

int apple[101][101];

int distribute(int m,int n){
    if(apple[m][n]!=-1) return apple[m][n];

    if(m<n){
        apple[m][n] = 0;
        return 0;
    }

    if(m==n || n == 1){
        apple[m][n] = 1;
        return 1;
    }
    apple[m][n] = 0;
    for(int i=1;i<=n;i++)
        apple[m][n]+=distribute(m-n,i);
    return apple[m][n];
}

int solve(int m,int n){
    if(m<0) return 0;
    if(m == 0 || n == 1)    return 1;
    return solve(m-n,n)+solve(m,n-1);
}

int main(){
    int m,n;
    memset(apple,-1,sizeof(apple));
    scanf("%d %d%*c",&m,&n);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans += distribute(m,n);

    printf("%d\n",ans);
    printf("%d\n",solve(m,n));
    return 0;
}