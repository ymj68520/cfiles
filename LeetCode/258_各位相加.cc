#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int addDigits(int num) {
    int ret = 0;
    while(num > 0){
        ret+= num%10;
        num/= 10;
    }
    if(ret >= 10)    ret = addDigits(ret);
    return ret;
}

int main(){
    cout << addDigits(38) << endl;

    return 0;
}