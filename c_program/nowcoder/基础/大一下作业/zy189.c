#include <stdio.h>
#include <ctype.h>

int main (){
    int n;
    scanf("%d",&n);
    int ar[101];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
        getchar();
    }
    int terget;
    scanf("%d",&terget);
    for(i=0;i<n;i++){
        if(ar[i] == terget){
            printf("%d",i+1);
        }
    }

    return 0;
}