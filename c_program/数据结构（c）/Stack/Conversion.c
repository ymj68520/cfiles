#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//将非负十进制数转化为八进制
int main (){
    struct SqStack S;
    InitStack(&S);
    int N;
    scanf("%d",&N);
    while(N){
        Push(&S,N%8);
        N /= 8;
    }
    int e;
    while(!StackEmpty(S)){
        Pop(&S,&e);
        printf("%d",e);
    }
    putchar('\n');
    return 0;
}