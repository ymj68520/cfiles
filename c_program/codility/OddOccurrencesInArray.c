#include <stdio.h>

int solution(int A[], int N);

int main(){
    int temp;
    int A[] = {9,3,9,3,9,7,9};
    temp = solution(A,7);
    printf("%d\n",temp);
    return 0;
}
int travel (int n,int *ar){
    int i=0;
    int flag = 0;
    while(*(ar+i)!=-2){
        if(*(ar+i)==n){
            flag = 1;
            break;
        }
        i++;
    }
    return flag;
}
int solution(int A[], int N){
    int i;
    int j;
    int already[100]={-1};
    already[100] = -2;
    for(i=0;i<N;++i){
        if(travel(i,already)){
            continue;
        }
        for(j=i+1;j<N;j++){
            if(A[i]==A[j]){
                already[j] = j;
                break;
            }
        }
        if(j==N && A[i]!=A[N-1])
            break;
    }
    return A[i];
}