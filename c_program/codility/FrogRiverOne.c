#include <stdio.h>
int solution(int X, int A[], int N);
int main(){
    int A[] = {1,3,1,4,2,3,5,4};
    printf("%d\n",solution(5,A,8));

    return 0;
}

int solution(int X, int A[], int N){
    int time[X];
    for(int i=0; i<X;i++)
        time[i] = 100001;
    for(int i=0;i<N;++i){
        if(i+1<time[A[i]-1])
            time[A[i]-1] = i+1;
    }
    int temp = 0;
    for(int i=0;i<X;i++){
        if(time[i]==100001)
            return -1;
        if(time[i]>temp)
            temp = time[i];
    }
    return temp-1;
}