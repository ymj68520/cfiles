#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int  pt[50];
    for(int i=0;i<n;i++){
        scanf("%d",&pt[i]);
    }
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=i;j<n;j++){
            if(pt[j]<pt[i]){
                temp = pt[j];
                pt[j] = pt[i];
                pt[i] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",pt[i]);
        if(i<n-1)
            putchar(',');
    }

    return 0;
}