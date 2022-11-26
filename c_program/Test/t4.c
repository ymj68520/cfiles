#include <stdio.h>

int main(){
    int a,b[10];
    char t[3];
    t[0] ='a';
    t[1] = '3';
    t[2] = (int)t[1];
    if(t[1]>'')
    puts(t);
    a = sizeof(b);
    printf("%d",a);
    return 0;
}