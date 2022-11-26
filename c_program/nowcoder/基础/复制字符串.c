#include <stdio.h>

int main(){
    char ch;
    while((ch=getchar())!=EOF){
        putchar(ch);
    }
    putchar('\n');
    return 0 ;
}