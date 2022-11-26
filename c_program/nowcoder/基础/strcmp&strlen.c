#include <stdio.h>

int strcmp(const char str1[],const char str2[]){
    int i=0;
    while(str1[i]!= '\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i])
            return str1[i]-str2[i];
        i++;
    }
    return 0;
}

int strlen(const char str[]){
    int n=0;
    while(str[n]!='\0')
        n++;
    return n;
}