#include <stdio.h>

int main(){
    long N;
    scanf("%ld",&N);
    int flag;
    if(N>=0)
        flag = 1;
    else
        flag = 0;
    int integer[10];
    N = (N>=0)?N:-N;
    int i=0;
    while(N>0){
        integer[i] = N%10;
        N/=10;
        i++;
    }
    N = 0;
    for(int j=0;j<i;j++){
        N = N*10+integer[j];
    }
    if(!flag)
        N = -N;
    printf("%ld",N);
    return 0;
}