#include <stdio.h>
#include <ctype.h>

int main(){
    char string[5001];
    char ch = tolower(getchar());
    int len=0;
    while(ch !='\n'){
        string[len] = ch;
        ch = tolower(getchar());
        len++;
    }
    for(int i=0;i<len/2;i++){
        if(string[i]!=string[len-1-i]){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}