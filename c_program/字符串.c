#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
     abc#c
     abc
*/
const int MAX_SIZE = 100;
int is_eaqul(char *S, char *T){
    int S_len = strlen(S),T_len = strlen(T);
    char *st = (char *)malloc(sizeof(char)),*tt = (char *)malloc(sizeof(char));
    int i,j;
    for(i=0,j=0;i<S_len;i++){
        if(S[i]=='#'&&j>0){
            j--;
            st[j] = '\0';
            continue;
        }
        if(S[i]!='#'){
            st[j] = S[i];
            j++;
            st = (char *)realloc(st,(j+1)*sizeof(char));
        }
    }
    
    for(i=0,j=0;i<T_len;i++){
        if(T[i]=='#'&&j>0){
            j--;
            tt[j] = '\0';
            continue;
        }
        if(T[i]!='#'){
            tt[j] = T[i];
            j++;
            tt = (char *)realloc(tt,(j+1)*sizeof(char));
        }
    }
    if(j<0)
        return 0;
    if(strcmp(st,tt)==0)
        return 1;
    else
        return 0;
}
bool backspaceCompare(char *S, char *T){
    int i=strlen(S),j=strlen(T);
    // 倒序

}
int main(){
    char S[MAX_SIZE],T[MAX_SIZE];
    scanf("%s%*c",S);
    scanf("%s%*c",T);
    printf("%d\n",is_eaqul(S,T));
    printf("%d\n",backspaceCompare(S,T));
}