// 输入数组P 并按照字典序输出A各元素的所有全排列。
#include <iostream>

void print_permutation(int n, int *A, int *P, int cur){
    if(cur == n){
        for(int i=0;i<n;i++)    printf("%d ",A[i]);
        printf("\n");
    }
    // 不输入 1 1 1的情况：
    // else for(int i=1;i<=n;i++){
    //     int ok = 1;
    //     for(int j=0;j<cur;j++)
    //         if(A[j] == P[i])    ok = 0;

    //     if(ok){
    //         A[cur] = P[i];
    //         print_permutation(n,A,P,cur+1);
    //     }
    // }
    else for(int i=0; i<n; i++) if(!i|| P[i] != P[i-1]){
        int c1 = 0, c2 = 0;
        for(int j=0; j<cur; j++)    if(A[j]==P[i]) c1++;
        for(int j=0; j<n; j++)  if(P[i]==P[j])  c2++;
        if(c1 < c2){
            A[cur] = P[i];
            print_permutation(n,A,P,cur+1);
        }
    }
}


int main(){
    int A[3];
    int P[3] = {1,1,1};
    print_permutation(3,A,P,0);

    return 0;
}