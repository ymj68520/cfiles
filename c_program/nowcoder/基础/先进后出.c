#include <stdio.h>

void inverse(int * ar,int n);

int main (){
    int t,n;
    int i,j;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        int a[n];
        for (j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        inverse(a, n);
    }

    return 0;
}

void inverse (int * ar,int n){
    int temp,i;
    for(i=0;i<n/2;i++){
        temp = ar[i];
        ar[i] = ar[n-i-1];
        ar[n-i-1] = temp;
    }
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    putchar('\n');
    return;
}