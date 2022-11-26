#include <stdio.h>

int main(){
    int n;
    int des[3];
    for(int i=0;i<3;i++){
        scanf("%d",&des[i]);
        getchar();
        if(des[i]<= 0) printf("error");
    }
    int temp;
    for(int i = 0;i<3;i++){
        for(int j=i;j<3;j++){
            if(des[j]<des[i]){
                temp = des[j];
                des[j] = des[i];
                des[i] = temp;
            }
        }
    }
    if(des[0]+des[1]>des[2]) printf("yes");
    else printf("no");

    return 0;
}