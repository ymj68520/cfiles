#include <stdio.h>

int main(){
    int a[5],des[5]={0};
    int num = 0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(a[i]>=0){
            num++;
            des[i]++;
        }
    }
    int s=0;
    for(int i=0;i<5;i++){
        if(des[i]>0)
            s+=a[i];
    }
    printf("%d %d",num,s);

    return 0;
}