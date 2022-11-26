#include <iostream>
#include <cstring>
// BM算法
// 从右往左遍历，找到第一个不同的位置，然后查找模式串中第一个与该位置相同的字符，
// 然后将两个位置对齐。
// 如果后面有已经匹配的部分子串，则查找模式串前是否有已经匹配的部分子串，若找到则对齐这匹配的子串。
// 极端情况，坏字符一直出现在结尾。好结尾一直不出现！
// 退化为暴力搜索。

using namespace std;
// BM 解法
// 比较主串S中第一个出现的子串T，返回T出现的第一个位置
// 找不到返回-1
int BMstring_BC(char *S, char *T){
    int lenT = strlen(T);
    int lenS = strlen(S);
    int i,j,k;
    for(i=0;i<lenS;){
        for(j=lenT-1,k=0;j>=0;j--)
            if(T[j]!=S[i+j])
                break;
        if(j==-1)
            return i;
        for(k=j;k>=0;k--)
            if(T[k] == S[i+k])
                break;
        i += j-k;
    }
    return -1;
}
// 从右往左匹配，找到坏字符（意味着坏字符后面的串是匹配的，即该串为好后缀），
// 往左寻找模式串中是否还存在好后缀，若有，将模式串右移到该位置与主串的好后缀对齐。
// 若模式串中再没有好后缀，则右移到好后缀的往右错一位的位置。
int BMstring_GG(char *S, char *T){
    int lenT = strlen(T);
    int lenS = strlen(S);
    int i,j,k;
    for(i=0;i<lenS;){
        for(j=lenT-1,k=0;j>=0;j--)
            if(T[j] != S[i+j])
                break;
        if(j==-1)
            return i;
        char demo[lenT-j];
        for(int t=j;t>=0;t--)
            demo[j-t] = T[t];
        k = BMstring_GG(T, T+j);
        if(k == 0){
            i += lenT-j;
            continue;
        }
        i += j-k+1;        
    }
    return -1;
}
// 暴力解，只为比对结果
int BFstring(char *S, char *T){
    int lenS = strlen(S);
    int lenT = strlen(T);
    int i,j;
    for(i=0;i<lenS;++i){
        for(j=0;j<lenT;j++){
            if(S[i+j]!=T[j])
                break;
        }
        if(j==lenT)
            return i;
    }
    return -1;
}

int main(){
    char S[] = "0000000000000000000000000000000000000000001";
    char T[] = "01";
    printf("%d\n",BFstring(S,T));
    printf("%d\n",BMstring_BC(S,T));
    printf("%d\n",BMstring_GG(S,T));

    return 0;
}
