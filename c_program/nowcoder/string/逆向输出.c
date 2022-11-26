#include <stdio.h>

int main (){
    char ch[1001];
    int len = 0;
    char cha = getchar();
    while(cha!='\n'){
        ch[len] = cha;
        cha = getchar();
        len++; 
    }
    for(int i=len-1;i>=0;i--)
        putchar(ch[i]);
    return 0;
}