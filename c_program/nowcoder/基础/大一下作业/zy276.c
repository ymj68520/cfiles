//韩信点兵
#include <stdio.h>
int main() {
    int n;
    if(~scanf("%d",&n)) printf("error");
    int n1[100],n2[100];
    for(int i=0;i<n;i++){
        if(scanf("%d %d",&n1[i],&n2[i])!=2) printf("error");
    }
    int num;
    int i;
    for(i=0;i<n;i++){
        for(int j=i,num=0;num!=n;j++){
            if(i%n1[j]==n2[j]) num++;
        }
    }
    printf("%d",i);
    return 0;
}