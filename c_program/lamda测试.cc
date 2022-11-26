#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int inverse(int x, int mod){
    // 计算x模mod的逆 要求模数为素数 使用费马小定理
    if(x>mod)
        x %= mod;
    int i(1),j(0);
    map<int,int> temp;
    while(i!=mod-2){
        temp[i+j] = (int)pow(x,i+j);
        temp[i+j]%= mod;
        
        i += j;

        if(2*i > mod-2){
            for(j=1;j<=i;j*=2)
                if(i+j > mod-2){
                    j /= 2;
                    break;
                }
        }
        else{
            i *= 2; j = 0;
        }
    }
    if(temp[mod-2]<0)
        temp[mod-2]+=mod;
    return temp[mod-2];
}

int gcd(int x, int y){
    if(x<=0 || y<=0)
        return -1;
    
    while(x!=y){
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return y;
}
int lamda(int x1,int y1,int x2,int y2,int a,int mod){
    if(x1<0 && x2<0)
        return -1;
    int re;
    if(x1==x2 && y1 == y2){
        // 同一个点不为无穷 计算lamda
        // lamda = 3x^{2}+a / 2y;
        int x = 3*x1*x1+a;
        int y = 2*y1;
        int gcd_xy = gcd(x,y);
        x/=gcd_xy; y/=gcd_xy;
        if(y == 1)
            re = x;
        else{
        re = x * inverse(y,mod);
        re %= mod;
        }
    }
    else{
        // 不同计算斜率
        int x = x1-x2;
        x = (x<0)?-x:x;
        int y = y1-y2;
        y = (y<0)?-y:y;
        int gcd_xy = gcd(x,y);
        x/=gcd_xy; y/=gcd_xy;
        if(y==1)
            re = x;
        else{
            re =  y * inverse(x,mod);
            re %= mod;
        }
    }
    return re;
}

int main(){
    printf("%d\n",lamda(16,13,5,1,2,17));

    return 0;
}