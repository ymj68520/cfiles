#include <stdio.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ar[100000] = {0};
    int i;
    for(i=0;i<N;++i){
        if(A[i]>N || A[i]<=0)
            return 0;
        ar[A[i]-1]++;
        if(ar[A[i]-1]==2)
            return 0;
    }
    for(int j=0;j<N;j++){
        if(ar[j]==0)
            return 0;
    }

    return 1;
}

int main (){

}