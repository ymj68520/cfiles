/*
    一个图像1024像素，使用四分树表示。四分树先序遍历结果确定唯一的一棵树。
    计算黑色像素数的总和。
    p表示中间节点，f表示黑色，e表示白色。
*/
#include <iostream>
#include <cstring>
using namespace std;

const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len],cnt;

// 把字符串s[p..]导出到以（r,c)为左上角，边长为w的缓冲区中
// 2 1
// 3 4
void draw(const char *s,int &p,int r,int c,int w){
    char ch = s[p++];
    if(ch == 'p'){
        draw(s,p,r,    c+w/2,w/2);  // 1
        draw(s,p,r,    c,    w/2);  // 2
        draw(s,p,r+w/2,c,    w/2);  // 3
        draw(s,p,r+w/2,c+w/2,w/2);  // 4
    }
    else if(ch == 'f'){
        for(int i=r;i<r+w;i++)
            for(int j=c;j<c+w;j++)
                if(buf[i][j]==0){ buf[i][j]=1;cnt++;}
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(buf,0,sizeof(buf));
        cnt = 0;
        for(int i=0;i<2;i++){
            scanf("%s",s);
            int p = 0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}
