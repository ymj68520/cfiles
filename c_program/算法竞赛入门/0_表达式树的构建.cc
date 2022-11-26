#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 1000+10;
int lch[maxn],rch[maxn];
char op[maxn];
int nc=0;   // 节点数
// 从表达式的x到y构建树。
int build_tree(char *s, int x, int y){
    int i,c1=-1, c2=-1,p=0;
    int u; // 节点编号
    if(y-x == 1){// 仅一个字符，构建单独节点
        u = ++nc;   // 将u设置为当前节点个数，总个数+1
        lch[u] = rch[u] = 0;    // 只有一个节点，因此再无子节点，置为0
        op[u] = s[x];   // 设置节点的值
        return u;   // return
    }
    for(int i=x;i<y;i++){   // p 用来记录当前是否处于括号中
        switch (s[i]){
            case '(': p++;break;
            case ')': p--;break;
            case '+':
            case '-':if(!p) c1=i;break; // 记录不在括号中，且运算符为+-的位置
            case '*':
            case '/':if(!p) c2=i;break; // 记录不在括号中，且运算符为*/的位置
        }
    }
    if(c1<0)    c1 = c2;    // 如果括号外没有+-，则置*/
    // 如果括号外没有+-且没有*/，表明表达式处于一对括号中
    if(c1<0)    return build_tree(s,x+1,y-1);   
    u = ++nc;   // 获取当前节点编号
    lch[u] = build_tree(s,x,c1);    // 处理左子树
    rch[u] = build_tree(s,c1+1,y);  // 处理右子树
    op[u]  = s[c1];
    return u;
}
void display(int u){
    if(lch[u]!=0)   display(lch[u]);
    if(rch[u]!=0)   display(rch[u]);
    cout << op[u] << ' ';
}
int main(){
    char s[] = "a+b*(c-d)-e/f";
    int u = build_tree(s,0,13);
    display(u);cout << endl;

    return 0;
}