#include <iostream>
using namespace std;

bool isprime(int n){
    // 本题中数字和从3开始不会出现小于2的情况：
    if(n<4) return true; 
    for(int i=2;i*i<=n;i++)
        if(!(n%i))  return false;
    return true;
}
int n=0;
int A[11] = {0};
int vis[11] = {0};

void search(int cur){
    if(cur == n && isprime(A[0]+A[n-1])){
        for(int i=0;i<n;i++)    printf("%d ",A[i]);
        printf("\n");
    } 
    else for(int i=1; i<=n; i++) if(!vis[i] && isprime(i+A[cur-1])){
        A[cur] = i;
        vis[i] = 1;
        search(cur+1);
        vis[i] = 0; // 改回来！！！！！ 很重要！！！！
    }
}

int main(){
    n = 6;
    search(0);

    return 0;
}
