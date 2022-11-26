#include <stdio.h>

union demo1
{
    int a;
    double b;
};


int main(){
    union demo1 abc;
    int s = sizeof(abc);
    printf("%d\n",s);
    abc.a = 1;
    printf("%d,%0.1lf\n",abc.a,abc.b);
    abc.b = 1.0;
    printf("%d,%0.1lf\n",abc.a,abc.b);
}