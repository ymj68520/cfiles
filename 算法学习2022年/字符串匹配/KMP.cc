// 字符串匹配KMP算法
// PMT值，前缀与后缀最长公共子串。
// profix：每一个下标位置对应一个PMT值，组成的数组。
// next数组：Profix数组右移一位，补-1，得next数组。

#include <iostream>
#include <cstring>
using namespace std;

void get_next(int *next, char *T, int lenT){
    int i(0),j(-1);next[i]=-1;
    while(i<lenT-1){
        if(j==-1 || T[i] == T[j]){
            i++;j++;
            next[i] = j;
        }
        else
            j = next[j];
        
    }
}
int kmp(char *S, char *T,int next[], int lenS,int lenT){
    int i(0),j(0);
    while(i<lenS){
        if(j==-1 || S[i]==T[j]){
            i++;++j;
        }
        else
            j = next[j];
    }
    if(j>=lenT)
        return i-lenT;
    else
        return -1;
}

int main(){
    char S[] = "000000000000000000000000000000000000000000001";
    char T[] = "00001";
    int lenT = strlen(T);
    int lenS = strlen(S);
    int next[lenT];
    puts("next: ");
    get_next(next,T,lenT);
    for(int i=0;i<lenT;i++)
        printf("%d, ",next[i]);
    puts("Location: ");
    printf("%d\n",kmp(S,T,next,lenS,lenT));
    return 0;
}