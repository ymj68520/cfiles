#include <stdio.h>

int main(){
    float f,c;
    
    f = 189.0;
    c = (5.0 * (f-32)) / 9 ;
    
    int a = 2;

    printf("f=%.1f\nc=%.1f\n",f,c); //%d %f  %3d %3.2f
    printf("%-3d",a);
    putchar('3');

    return 0 ;
}