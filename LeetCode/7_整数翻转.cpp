// 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

// 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

// 假设环境不允许存储 64 位整数（有符号或无符号）。

#include <iostream>
using namespace std;

int reverse(int x) {
    
    int ans=0,temp=0;
    while(x!=0){
        temp = x%10;
        if(ans > 214748364 || (ans == 214748364 && temp>7))
            return 0;
        if(ans < -214748364 || (ans == -24748364 && temp<-8))
            return 0;
        x /= 10;
        ans = ans*10 + temp;
    }
        return ans;
}

int main(){
    int temp[] = {123,1534236469,3423423,-123,-1,120};
    for(int i=0;i<6;i++)
        cout << temp[i] << ": " << reverse(temp[i]) << endl;

    return 0;
}

