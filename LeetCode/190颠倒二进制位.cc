#include <iostream>
using namespace std;
uint32_t M1 = 0x55555555;
uint32_t M2 = 0x33333333;
uint32_t M3 = 0x0f0f0f0f;
uint32_t M4 = 0x00ff00ff;

uint32_t reverseBits1(uint32_t n){
    n = n >> 1 & M1 | (n & M1) << 1;
    n = n >> 2 & M2 | (n & M2) << 2;
    n = n >> 4 & M3 | (n & M3) << 4;
    n = n >> 8 & M4 | (n & M4) << 8;
    return n >> 16 | n << 16;
}

int main(){
    cout << reverseBits1(0x01) << endl;

    return 0;
}