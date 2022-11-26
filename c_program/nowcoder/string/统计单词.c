#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    char target[50];
    int i=0;
    scanf("%s",target);
    getchar();
    while(target[i]!='\0'){
        target[i]=tolower(target[i]);
        i++;
    }
    target[i] = '\0';
    char source[50];
    int position = 100000;
    int al_lenth=0;
    int count=0;
    char ch;
    int space=0;
    while(!isalpha(ch = getchar()))
        space++;
    ungetc(ch,stdin);
    while(1){
        scanf("%s",source);
        i=0;
        while(source[i]!='\0'){
            tolower(source[i]);
            if(!isalpha(source[i]))
                source[i] = '\0';
            i++;
        }

        if(!strcmp(target,source)){
            count++;
            position = (position>al_lenth)?al_lenth:position;
        }
        al_lenth +=i+1;
        ch=getchar();
        if(ch == '\n')
            break;
    }
    if(count)
        printf("%d %d",count,position);
    else
        printf("-1");
    return 0;
}