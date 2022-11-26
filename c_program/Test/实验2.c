#include<stdio.h>
int main ()
{
   int m,n;
   for (m=1;m<10;m++)
    {
       for(n=1;n<=m;n++)
    {
       printf ("%d*%d=%2d ",n,m,m*n);
    }
       printf ("\n");
    }
     
} 
