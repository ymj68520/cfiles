#include <iostream>
#include <algorithm>
using namespace std;

int tot=0,best=0;
int A[10010]={0};
// 暴力枚举:
int bigs(int n){
    tot=0;
    best = A[1];
    for(int i=1;i<=n;i++){
        for(int j=i; j<=n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){ sum+=A[k]; tot++;}
            if(sum>best)    best = sum;
        }
    }
    return best;
}
// 分析上界后优化为n^2
int bigs2(int n){
    int S[n+10];
    S[0] = 0;
    for(int i=1; i<=n; i++) S[i] = S[i-1] + A[i];
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            best = max(best, S[j]-S[i-1]);
    return best;
}
// 使用分治法！(1.划分问题。2.递归求解。3.合并问题)
int maxsum(int *A, int x, int y){
    if(y-x==1)  return A[x];
    int m = x+(y-x)/2;
    int maxs = max(maxsum(A,x,m),maxsum(A,m,y));
    int v,L,R;
    v=0; L=A[m-1];
    for(int i=m-1; i>=x; i--)   L=max(L, v+=A[i]);
    v=0; R=A[m];
    for(int i=m; i<y; i++)  R = max(R, v+=A[i]);
    return max(maxs, L+R);
}