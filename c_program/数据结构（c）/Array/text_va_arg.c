#include <stdio.h>
#include <stdarg.h>

double are(int n,...);

int main (){
    printf("%lf\n",are(2,4.0,6.0));
    return 0;
}

double are (int n,...){
    double a=0;
    va_list args;
    va_start(args,n);
    for(int i=0;i<n;++i)
        a += va_arg(args,double);
    va_end(args);

    return a/n;
}