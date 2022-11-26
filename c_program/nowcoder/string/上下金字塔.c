#include <stdio.h>

void print(int);
int abs(int);
int main(){
    int source[9];
    int n=0;
    while(scanf("%d",source+n)!=EOF){
        n++;
    }
    for(int i=0;i<n;i++){
        print(source[i]);
    }
}
void print(int n){
    int row = 2*n - 1;
    int m=2;
    for(int i=1;i<=row;i++){
        for(int j=0;j<abs(n-i);j++)
            printf(" ");
        if(i<=n){
            for(int k=0;k<(2*i-1);k++)
                printf("*");
            printf("\n");
        }
        else{
            for(int k=0;k<(2*(i-m)-1);k++){
                printf("*");
            }
            printf("\n");
            m+=2;
        }
    }
    return;
}
int abs(int n){
    (n>0) ? n : (-n);
    return n;
}