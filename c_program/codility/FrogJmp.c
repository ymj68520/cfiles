#include <stdio.h>

int solution(int X, int Y, int D);

int main (){
    printf("%d\n",solution(10,85,30));
}

int solution(int X, int Y, int D){
    int i=0;
    i = (Y-X)/D;
    if((Y-X)%D)
        i++;
    return i;
}