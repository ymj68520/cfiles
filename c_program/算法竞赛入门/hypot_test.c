#include <stdio.h>
#include <math.h>

int main(){
    double x1=3,x2=4;
    double x3 = hypot(x1,x2);
    printf("%.0lf\n",x3);
    double  m = sqrt(3);
    printf("%lf\n",floor(m+0.5));
    return 0;
}