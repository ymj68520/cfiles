#include <string.h>
#include <stdio.h>
#include <stdbool.h>
int main(){
    bool test[10];
    memset(test,false,sizeof(bool)*10);  // 不能写在函数外- - 谁知道为啥= =
    for(int i=0;i<10;i++)
        printf("%d : ",test[i]);
    return 0;
}