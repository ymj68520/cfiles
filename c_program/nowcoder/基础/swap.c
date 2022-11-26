#include <stdio.h>
#include <assert.h>

int main(){
    int a = 10;
    int b = 9;
    puts("交换前：");
    printf("a = %d\nb = %d\n",a,b);
    // ****************
    a^=b^=a^=b;
    puts("异或交换后：");
    printf("a = %d\nb = %d\n",a,b);
    // ****************
    a = a+b;
    b = a-b;
    a = a-b;
    puts("加减交换后：");
    printf("a = %d\nb = %d\n",a,b);
    return 0;
}