#include <stdio.h>
#include <ctype.h>

int main(){
    char ch;
    int count = 0;
    while(~scanf("%c",&ch)){
        if(isalnum(ch))
            count++;
    }
    printf("%d",count);
}