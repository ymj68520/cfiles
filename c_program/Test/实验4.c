#include<stdio.h>
int main()
{
    int i,j,n,a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
    {
        if(a[i]<a[j])
            {
                a[i]=j+1;
            break;}
    }
    if(a[i]>=a[n-1]&&a[i]!=j+1)
        a[i]=0;
    else if(a[i]<a[n-1]&&a[i]!=j+1)
        a[i]=a[n-1];
    }
    for(j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
}
