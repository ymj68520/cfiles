#include <stdio.h>

int soulution (int A[],int N);

int main(){
    int A[] = {0,1,0,1,1};
    int N = 5;
    printf("%d\n",soulution(A,N));

    return 0;
}
int soulution (int A[],int N){
    int num[2] = {0,0};
    for(int i=0;i<N;i++){
        if(A[i]==0)
            num[0]++;
        else
            num[1]++;
    }
    for(int i=1;i<N;i++){
        int n0 = num[0];
        int n1 = num[1];
        while(A[i]!=A[0])
            i++;
    }

    return ;
}