#include <stdio.h>

int main(){
    int n;
    int a,b;
    int c=0,d=0;
    scanf("%d %d",&a,&b);
    int max = (a>b)?a:b;
    for(int i=2;i<max-1;i++){
        if(a%i==0 && b%i==0){
            c=i;
        }
        
        if(i>a || i>b) c=1;
    }
    for(int i=2;;i++){
        if(i%a==0 &&i%b==0) d=i;
        if(d!=0) break;
    }
    printf("%d,%d",c,d);
    return 0;
}