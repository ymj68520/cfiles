#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next(char *T,int **next){
    int i=0,j=-1,T_len = strlen(T);
    (*next) = (int *)malloc(T_len*sizeof(int));
    (*next)[0] = -1;
    while(i<T_len-1){
        if(j==-1||T[i]==T[j]){
            i++;j++;
            (*next)[i] = j;
        }
        else
            j = (*next)[j];
    }
    for(int i=0;i<strlen(T);++i)
        printf("%d ",(*next)[i]);
    putchar('\n');
}
int Index_Kmp(char *S,char *T,int *next,int pos){
    int i=pos-1,j=0;
    int S_len = strlen(S),T_len = strlen(T);
    while(i<S_len && j<T_len){
        if(j==-1 || S[i]==T[j]){
            ++i;
            ++j;
        }
        else 
            j = next[j];
    }
    if(j>=T_len)
        return i-T_len;
    else 
        return -1;
}
int main(){
    char T[] = "abaabcac";
    char S[] = "asdaefgsfdgdsfgabaabcacadfafsdfasdfsfg";
    int *next;
    get_next(T,&next);
    for(int i=0;i<strlen(T);++i)
        printf("%d ",next[i]);
    putchar('\n');
    printf("%d",Index_Kmp(S,T,next,1));
    return 0;
}