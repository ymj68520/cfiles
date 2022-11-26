#include <stdio.h>

int main(){
    int n,i;
    double par;
    int a[100];
    while((scanf("%d",&n))!=EOF){
        int s=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            s+=a[i];
        }
        par = (double)s/(double)n;
        for(i=0;i<n;i++){
            if(a[i]<par){
                printf("%d ",a[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}