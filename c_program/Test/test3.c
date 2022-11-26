#include <stdio.h>

int main(){
    char ch = '0';
    printf("%d\n",ch);
    const int **pp2;
    int *p1;
    const int n = 13;
    printf("%p %p %p\n",&n,pp2,p1);
    pp2 = &p1;  //类型不匹配的警告
    *pp2 = &n;
    *p1 = 10;
    printf("%p %p %p\n",&n,pp2,p1);
    printf("%d %d %d",n,**pp2,*p1);
    return 0;
}