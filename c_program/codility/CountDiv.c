#include <stdio.h>

int solution (int ,int ,int );

int main (){
    printf("%d",solution(26,200000,2));
    puts(" ");
    return 0;
}

int solution (int A,int B,int K){
    int n=0;
    n = B/K - A/K;
    if(!(A%K))
        n++;
    return n;
}