#include <stdio.h>

int main (){
    char ch[10000];
    int i=0;
    while((ch[i]=getchar()) != '\n'){
        i++;
    }
    int a=0,d=0;
    for(int k=0;k<i;k++){
        if(ch[k] == 'a') a++;
        if(ch[k] == 'd') d++;
    }
    printf("a:%d,d:%d",a,d);

    return 0;
}