#include <stdio.h>

int solution(int A[], int N);
int main(){
    int A[] = {2,3,1,5};
    printf("%d\n",solution(A,4));
    return 0;
}
int solution(int A[], int N){
    if(N==0)    return 0;
    int ar[N+1];
    for(int i=0;i<N+1;i++)
        ar[i] = 0;
    int i;
    for(i=0;i<N;++i)
        ar[A[i]-1] = A[i];
    i = 0;
    while(ar[i]!=0)
        i++;
    
    return i+1;
    
    
}