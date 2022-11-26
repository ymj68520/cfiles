#include <stdio.h>

int sum(int *,int ,int );

int min(int *A,int );
int solution(int A[], int N);
int main (){
    int A[] = {1000,3000};
    printf("%d\n",solution(A,2));
    return 0;
}

int sum(int *A, int start, int end){
    int s=0;
    for(int i=start; i<end;++i)
        s+=A[i];
    return s;
}
int min(int *A,int end){
    int temp=1000000;
    for(int i=0;i<end;i++){
        if(A[i]<temp)
            temp = A[i];
    }
    return temp;
}
int solution(int A[], int N){
    int pre,back;
    int ans;
    int AR[N-1];
    for(int i=1;i<N;i++){
        pre = sum(A,0,i);
        back = sum(A,i,N);
        ans = (pre>back)?pre-back:back-pre;
        AR[i-1] = ans;
    }
    return min(AR,N-1);
}
