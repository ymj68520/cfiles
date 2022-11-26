#include <stdio.h>
#include <stdlib.h>

struct Results {
  int * A;
  int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int * A;
    A = (int *)malloc(M*sizeof(int));
    int len=0;
    while(*(S+len)!='\0')
        len++;
    int N_S[len];
    for(int i=0;i<len;i++)
        switch (S[i]){
            case 'A' : 
                N_S[i] = 1;
                break;
            case 'C' :
                N_S[i] = 2;
                break;
            case 'G' :
                N_S[i] = 3;
                break;
            default :
                N_S[i] = 4;
                break;
        }
    for(int j=0;j<M;j++){
        int temp = 5;
        for(int k=P[j];k<=Q[j];k++){
            if(temp>N_S[k])
                temp = N_S[k];
        }
        A[j] = temp;
    }

    result.A = A;
    result.M = M;
    
    return result;
}

int main(){
    int P[] = {2,5,0};
    int Q[] = {4,5,6};
    char S[] = {'C','A','G','C','C','T','A','\0'};
    struct Results re = solution(S,P,Q,3);
    for(int i=0;i<re.M;i++)
        printf("%d ",re.A[i]);
    return 0;
}