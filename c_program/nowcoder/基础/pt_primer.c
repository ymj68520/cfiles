#include <stdio.h>
#include <stdbool.h>

void pt_primer(int n);
bool is_primer(int n);

int main (){
    int n;
    scanf("%d",&n);
    pt_primer(n);
    return 0;
}

void pt_primer(int n){
    int i;
    for(i=2;i<=n;i++){
        if(is_primer(i))
            printf("%d ",i);
    }
    return;
}

bool is_primer(int n){
    int div;
    bool isprime;
    for(div=2,isprime=true;(div)*(div)<=n;div++){
        if(n%div==0){
            isprime = false;
            break;
        }
    }
    return isprime;
}