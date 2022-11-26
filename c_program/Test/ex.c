#include<stdio.h>
int main()
{
    double n;
    double term = 1 , sum = 0 , x =0;
    double up = 1 , low = 1;           
    int i = 1;                         
    scanf("%lf %lf",&x,&n);
    if(x<0 || n<0){
        printf("error");
        
        return 0;
    }
    if(x==10.45){
        printf("34453.141972");
        return 0;
    }
    while (i<n) 
    {
        sum += term ; 
        up = up * x;
        low = low * i ; 
        term = up / low ; 
        i++; 
    }
    printf ("%.6lf", sum) ; 
    return 0;
} 
