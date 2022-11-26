#include <iostream>
using namespace std;

/*
    问题描述：
        现在有n阶楼梯，每次只能爬一阶或者两阶，
        问：一共有多少种走法？
    递归公式：
    f(n)={
        1, n=1
        2, n=2
        f(n-1)+f(n-2), n>3
    }
*/

// 递归
int climbstair_digui(int n){
    if(n==1 || n==2)
        return n;
    return climbstair_digui(n-1)+climbstair_digui(n-2);
}
// 高复杂度，时间复杂度O(n^2)
// 重复计算，因为每一次分支递归都有可能计算前面计算过的！
// 比如：f6 = f5 + f4, f5 = f4 + f3, f4 = f3 + f2...
// 解决办法，存储计算结果，以空间换时间。
int already[100010] = {0};
int climbstair_ar(int n){
    if(n==1 || n==2)
        return n;
    if(0 != already[n])
        return already[n];
    already[n] = climbstair_ar(n-1)+climbstair_ar(n-2);
    return already[n];
}
// 使用哈希映射的解决办法
#include <map>
map<int,int> almap;
int climbstair_mp(int n){
    if(n==1||n==2)
        return n;
    if(0 != almap.count(n))
        return almap[n];
    int result = climbstair_mp(n-1)+climbstair_mp(n-2);
    almap[n] = result;
    return result;
}
// 时间复杂度约为O(n)!

// 非递归法求解！
// 自低向下，由已知累加。
// 使用两个单独的变量，存储两个可能的累加值
// 时间复杂度更低，内存复杂度更低！
int climbstair(int n){
    if(n==1||n==2)
        return n;
    int result = 0;
    int pre=2;
    int prepre=1;
    for(int i=3;i<=n;i++){
        result = pre + prepre;
        prepre = pre;
        pre = result;
    }
    return result;
}


int main(){
    int n;
    cin >> n;
    printf("%d\n",climbstair_digui(n));
    printf("%d\n",climbstair_ar(n));
    printf("%d\n",climbstair_mp(n));
    printf("%d\n",climbstair(n));

    return 0;
}
