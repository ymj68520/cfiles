#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
// // 暴力解 超时
// int countPrimes(int n) {
//     if(n<=2) return 0;
//     int c=0,i,j;
//     for(i=3;i<n;i++){
//         for(j=2;j*j<=i;j++)
//             if(i%j==0)  break;
//         if(j*j>i)   c++;
//     }
//     return c+1;
// }

int countPrimes(int n) {
    int count = 0;
    //一个 int 变量不知道占多少字节（但请注意，这里采用了常量）
    const int size = sizeof(int) * 8;
    vector<int> signs(n / size + 1,0);
    for (int i = 2; i < n; i++){
        //将元素和需确定得数字经行按位或运算，如果值改变，说明不存在该数字（未登记该数字），则其为质数。
        //在C++中，其提供了 bitset 来操作位，在此便不做介绍了。如果用了，可读性肯定会更好。
        //(当某个数为 2 的 n 次方时（n为自然数），其 & (n - 1) 所得值将等价于取余运算所得值)
        //*如果 x = 2^n ，则 x & (n - 1) == x % n
        //下面判断可以写成
        //if ((signs[i / size] & (1 << (i % 32))) == 0)
        if ((signs[i / size] & (1 << (i & (size - 1)))) == 0){
            count++;
            for (int j = i + i; j < n; j += i){
                //登记该数字
            	signs[j / size] |= 1 << (j & (size - 1));
            }
        }
    }
    return count;
}
int countPrimes_bitset(int n) {
    if(n<=2)    return 0;
    bitset<5000000> bt(0);
    int count = 0,i,j;
    for(i=3;i<n;i+=2){
        if(bt[i]) continue;
        for(j=2;j*j<n;j++)
            if(i%j==0)  break;
        if(j*j>i){
            count++;
            for(int k = j+j;k<n;k+=j)
                bt[k] = 1;
        }
    }
    return count;
}
int main(){
    int n = 100;

    cout << countPrimes(n) << endl;

    return 0;
}