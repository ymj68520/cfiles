#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isH(char *,int);

void main(){
    char *ch;
    char temp = getchar();
    int n =1;
    while(temp != '\n' && temp != ' '){
        ch = (char *)malloc(n*sizeof(char));
        ch[n-1] = temp;
        temp = getchar();
        n++;
    }
    printf("%s",ch);
    //scanf("%s",ch);
    //int len = strlen(ch);
    if(isH(ch,n))
        puts("Yes");
    else
        puts("No");
    
    return;
}
bool isH(char ch[],int n){
    char temp[n];
    for(int i=0;i<n;i++)
        temp[i] = ch[n-1-i];
    if(strcmp(temp,ch))
        return false;
    else
        return true;
}