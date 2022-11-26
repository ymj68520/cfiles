#include <stdio.h>

int main(){
    int a['z'+1]={0};
    char i,j;
    while((i=getchar())!=EOF){
        if(i>='a' && i<='z'){
            a[i]++;
        }
    }
    for(j='a';j<'z';j++){
        if(a[j]>0){
            printf("%c:%d\n",j,a[j]);
        }
    }
    return 0;
}