#include <stdio.h>

int solution(int A[], int N);
void select_sort (int a[], int n);

int main () {
    int A[] ={2};
    int result;

    result = solution(A,1);

    printf ("%d\n",result);

    return 0;
}

int solution(int A[], int N){
    select_sort(A, N);
    if(A[N-1]<0)  return 1;
    for(int i=0;i<N;++i){
        if(A[i+1]-A[i]!=1 && A[i+1]!=A[i]){
            return A[i]+1;
        }
    }
    return A[N]+1;
}

void select_sort (int a[], int n){
    int minindex,min;
    for(int i = 0; i < n; i++){
        minindex = i;
        min = a[minindex];
        for(int j = i + 1; j < n; j++){
            if(min > a[j]){
                min = a[j];
                minindex = j;
            }
        }
        if(minindex != i){
            a[minindex] = a[i];
            a[i] = min;
        }
    }
}