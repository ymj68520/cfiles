#include <stdio.h> //guo da chao shi 1s
#include <stdbool.h>

bool is_prime(int n);
int num_prime(int n);

int main (){
    int t,n;
    int i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        j = num_prime(n);
        printf("%d\n",j);
    }
    return 0;

}

bool is_prime(int n){
    bool isprime = true;
    int div;
    if(n==1){
        return isprime = false;
    }
    
    for(div=2;div*div<=n;div++){
        if((n%div)==0){
            isprime = false;
            break;
        }
    }
    return isprime;
}

int num_prime(int n){
    int i,j=0;
    for(i=1;i<=n;i++){
        if(is_prime(i)){
            j++;
        }
    }
    return j;
}
/*
#include<stdio.h>
int main()
{
    int i,j,n,a[1000001]={0};
    for(i=2;i<=1000;i++)
    {
        for(j=i*i;j<=1000000;j+=i)
            a[j]=1;
    }
    for(i=2;i<=1000000;i++)
    {
        if(!a[i])
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1];
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}
*/