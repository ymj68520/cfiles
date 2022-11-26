/*
    输入字符串 【表示Home键   】表示end键
    输出最终结果
*/

#include <iostream>
#include <cstring>

const int maxn = 10000 + 10;
int last,cur,next[maxn];
char s[maxn];
// 使用s存储串 使用next指示位置
int main (){
    while(scanf("%s",s+1)==1){
        int n = strlen(s);
        last = cur = 0;
        next[0] = 0;

        for(int i=1;i<=n;i++){
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else{
                next[i] = next[cur];    // 先为第i位的顺序赋值
                next[cur] = i;          // 改变当前位的顺序值
                if(cur == last) last = i;
                cur = i;
            }
        }
        for(int i=next[0];i!=0;i=next[i])   // 依照顺序打印
            printf ("%c",s[i]);
        putchar('\n');
    }
    return 0;
}