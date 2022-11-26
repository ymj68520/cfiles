#include <stdio.h>

int solution (int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ar[100001] = {0};
    int i,j;
    for(i=0;i<N;i++){
        if(A[i]<=0){
            i++;
        }
        ar[A[i]-1] = A[i];
    }
    for(j=0;j<N+1;j++){
        if(ar[j]==0)
            break;
    }
    return j+1;
}
int main (){
    int A[] = {1,3,6,4,1,2};
    printf("%d\n",solution(A,6));

    return 0;
}