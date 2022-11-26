#include <stdio.h>

int main(){
    int l,w,n;
    int minl,minw;
    scanf("%d",&n);
    for(w=0;w*w<=n;w++){
        for(l=w;l<=n;l++){
            if(l*w==n){
                minl = l;
                minw = w;
            }
        }
    }
    printf("%d %d",minw, minl);
    return 0;
}