#include <iostream>
#include <cstring>
using namespace std;
// 一一比对，暴力破解 BF算法
// 使用哈希算法，主串与模式串的哈希值作比较
// 定义一种二十六进制，将字符串转化为数字，取哈希函数为求和，比对和，移动时只做一次加法一次减法。
// 哈希冲突的情况下，极端情况退化为BF算法。

// 使用BF暴力搜索
// 比较主串S中第一个出现的子串T，返回T出现的第一个位置
// 找不到返回-1
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
// 使用哈希算法 哈希函数为字母和二十六进制模运算
// 比较主串S中第一个出现的子串T，返回T出现的第一个位置
// 找不到返回-1
int BKstring(char *S, char *T){
    int lenS = strlen(S);
    int lenT = strlen(T);
    int hashS(0),hashT(0),i,j;
    // 初始化哈希值
    for(int k=0;k<lenT;k++){
        hashS += (S[k] - '0');
        hashT += (T[k] - '0');
        hashS %= 26;
        hashT %= 26;
    }
    // printf("hashT: %d\nhashS: ",hashT);
    // 比对
    for(i=0;i<=lenS-lenT;++i){
        // printf("%d, ",hashS);
        if(hashS == hashT){
            int flag=1;
            for(int k=0;k<lenT;k++){
                if(S[i+k]!=T[k]){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                return i;
        }
        // 不匹配更新hashS
        hashS -= (S[i] - '0');
        hashS += (S[i+lenT] - '0');
        hashS %= 26;
    }
    // putchar('\n');
    return -1;
}

int main(){
    char S[] = "0000000000000000000000000000000000000000000000000000000001";
    char T[] = "001";
    printf("%d\n",BFstring(S,T));
    printf("%d\n",BKstring(S,T));

    return 0;
}