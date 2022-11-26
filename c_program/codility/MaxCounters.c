#include <stdio.h>
struct Results {
  int * C;
  int L; // Length of the array
};
int max(int A[],int N){
    int temp = 0;
    for(int i=0;i<N;i++)
        if(A[i]>temp)
            temp = A[i];

    return temp;
}
struct Results solution(int N, int A[], int M) {
    struct Results result;
    int counter[N];
    for(int i=0;i<N;++i)
        counter[i] = 0;
    int i;
    for(i=0;i<M;i++){
        if(A[i]==N+1){
            int mnum = max(counter,N);
            for(int j=0;j<N;++j)
                counter[j] = mnum;
            continue;
        }
        counter[A[i]-1]++;
    }
    result.C = counter;
    result.L = N;
    return result;
}
int main() {
    int A[] = {3,4,4,6,1,4,4};
    struct Results re = solution(5,A,7);
    for(int i=0;i<re.L;i++){
        printf("%d ",re.C[i]);
    }
    puts(" ");
    return 0;
}