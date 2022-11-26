#include <iostream>
#include <vector>
#include <cmath>
#include <map>
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
    return temp[mod-2];
}

int main(){
    int x = 2;
    int mod = 19;

    printf("%d\n",inverse(x,mod));
}