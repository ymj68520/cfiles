/*
    输入正整数k，找到所有的正整数x,y（x>=y)使得
        1/k = 1/x + 1/y
*/

#include <iostream>
using namespace std;

// 分数减法：计算1/k - 1/y, 返回x,如果不存在返回-1
int subtox(int k, int y){
    // 1/2 - 1/y = y-k / ky;
    // 即为判断: y-k | ky 
    int sub = y-k;
    int mul = y*k;
    if(mul/sub == (mul+sub-1)/sub)
        return mul/sub;
    else 
        return -1;    
}
void print(int k,int x,int y){
    printf("1/%d = 1/%d + 1/%d\n",k,x,y);
}
int main(){
    int k,y;
    int x[10000 + 100];     // 由题设的maxk决定数组大小
    while(cin >> k){
        int i(0),cnt(0);
        for(int y=k+1;y<=2*k;y++,i++){
            x[i] = subtox(k,y); 
            if(x[i]>0)
                cnt++;
        } 
        printf("%d\n",cnt); 
        for(int j=0;j<i;j++)
            if(x[j] > 0)
                print(k,x[j],k+j+1);
    }
    return 0;
}
