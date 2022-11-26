#include<stdio.h>
int main()
{
	int *p,a[9],i;
	
    for(i=0;i<9;i++)
	    scanf("%d",a+i);
	
    p=a;
    for(i=0;i<9;i++)
        a[i]=(p[i]+1)%9;
    
    p=a;
    for(i=0;i<9;i++)
	    printf("%d, ",p[i]);
    return 0;	
 }
