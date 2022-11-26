// 回文串 镜像串
// 镜像对照表：
// A-A E-3 H-H I-I J-L L-J M-M O-O S-2 T-T U-U V-V W-W X-X Y-Y Z-5 1-1 2-S 3-E 5-Z 8-8
#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char * msg[] = {"not a palindrome","a regular palindrome","a mirrored string",
"a mirrored palindrome"};

char r(char ch){
    if(isalpha(ch)) return rev[ch - 'A'];
    else return rev[ch-'0'+25];
}

int main(){
    char s[30];
    while(scanf("%s",s)==1){
        int len = strlen(s);
        int p=1,m=1;
        for(int i=0;i<(len+1)/2;i++){
            if(s[i]!=s[len-1-i])    p=0;    // 不是回文串
            if(r(s[i])!=s[len-1-i]) m =0;   // 不是镜像串
        }
        printf("%s -- is %s.\n\n",s,msg[m*2+p]);
    }
    return 0;
}
