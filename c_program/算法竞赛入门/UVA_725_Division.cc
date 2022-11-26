// 输入整数n(2<=n<=79)
// 按从小到大的顺序输出所有形如：
// abcde/fghij = n;
// 的表达式。其中a~j恰好为0~9的一个排列（可以有前导0,但都不相同）

// 不必枚举所有0~9的排列，只需枚举fghij就可以算出abcde，然后判断是否所有数字都不相同即可。
// 枚举量从10！下降到不到一万。

#include <iostream>
using namespace std;

bool isalright(int n, int m){
    if(m<1111 || n <1111)
        return false;
    int temp[10] = {0};
    for(int i=0;i<6;i++){
        int t = n%10;
        if(temp[t])
            return false;
        temp[t] = 1;
        t = m%10;
        if(temp[t])
            return false;
        temp[t] = 1;
        n/=10;m/=10;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1000;i<99999;i++){
        
    }
}