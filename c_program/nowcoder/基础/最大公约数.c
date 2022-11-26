#include <stdio.h>
#include <stdbool.h>

int is_max_div(int a, int b);

int main(){
    int a,b;
    int is_div;
    scanf("%d %d",&a,&b);
    is_div = is_max_div(a,b);
    printf("%d",is_div);
    return 0;
}

int is_max_div(int a, int b){
    int i,maxi;
    if(a < b){
        i = a;
        a = b;
        b = i;
    }
    for(i=1;i<=b;i++){
        if(a%i==0 && b%i==0){
            maxi = i;
        }
    }
    
    return maxi;

}