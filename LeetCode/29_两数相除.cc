#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
long dive(long a, long b){
    if(a<b) return 0;
    long cnt=1;
    long nb = b;
    while((nb+nb)<=a){
        cnt += cnt;
        nb += nb;
    }
    return cnt + dive(a-nb,b);
}
int divide(int dividend, int divisor) {
    if(!dividend)   return 0;
    if(divisor==-1){
        if(dividend == INT_MIN)
            return INT_MAX;
        else    
            return -dividend;
    }
    long a = abs(dividend);
    long b = abs(divisor);
    int sign = 1;
    if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
        sign = -1;
    long res = dive(a,b);
    if(sign>0)  return min(res, (long)INT_MAX);
    return -res;
}

int main(){
    cout << divide(INT_MAX, -100) << endl;
    return 0;
}