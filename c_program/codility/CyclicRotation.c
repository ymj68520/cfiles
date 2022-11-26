#include <stdio.h>

struct Results {
  int * A;
  int N; // Length of the array
};
struct Results solution(int A[], int N, int K);
int * travel(int *,int);
int main (){
    struct Results re;
    int a[] = {1,2,3,4,5};
    re.A = a;
    re.N = 5;
    re = solution(re.A,re.N,5);
    for(int i=0;i<5;++i){
        printf("%d",re.A[i]);
    }
    return 0;
}

int * travel(int *array,int n){
    int temp;
    temp = array[n-1];
    for(int i=n-1;i>0;--i)
        array[i] = array[i-1];
    array[0] = temp;

    return array;
}

struct Results solution(int A[], int N, int K){
    struct Results result;

    for(int i=0;i<K;i++)
        A = travel(A,N);    
    result.A = A;
    result.N = N;
    return result;
}