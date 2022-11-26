#include <stdio.h>
#include <string.h>

void get_next(int *next,char *T){
    int i=0,j=-1;next[0] = -1;
    int T_len = strlen(T);
    while(i<T_len){
        if(j==-1 || T[j]==T[i]){
            i++;j++;
            next[i] = j; 
        }
        else
            j = next[j];
    }
}
int Index_KMP(char *S,char *T,int pos){
    int i=pos-1,j=-1;
    int S_len = strlen(S);
    int T_len = strlen(T);
    int next[T_len];
    get_next(next,T);
    while(i<S_len){
        if(j==-1 || S[i]==S[j]){
            i++;j++;
        }else
            j = next[j];
    }
    if(j>T_len)
        return i-T_len;
    else
        return -1;
}

int main(){
    char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char t[] = "aaab";
    printf("%d\n",Index_KMP(s,t,0));
    return 0;
}