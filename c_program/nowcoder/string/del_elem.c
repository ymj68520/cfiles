#include <stdio.h>
int main()
{
    int n,del,i,t;
    while(scanf("%d",&n)!=EOF){
        t=0;
        int ar[n];
        for(i=0;i<n;i++){
            scanf("%d",&ar[i]);
        }
        scanf("%d",&del);
        for(i=0;i<n;i++){
            if(ar[i]==del&&t==0){
                t=1;
            }
            else printf("%d ",ar[i]);
        }
        printf("\n");
    }
    return 0;
}