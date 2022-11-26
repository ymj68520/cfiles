#include<stdio.h>
int main()
{
    int n;
    while( scanf("%d",&n)!=EOF)
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            int num_star=2*i-1;
            int num_space=(2*n-1-(2*i-1))/2;
            int j;
            for(j=1;j<=num_space;j++)
                printf(" ");
            for(j=1;j<=num_star;j++)
                printf("*");
            for(j=1;j<num_space;j++)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
