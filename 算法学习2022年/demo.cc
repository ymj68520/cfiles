#include <iostream>
using namespace std;

int main(){
    unsigned long long W[] = {0x2B7E1516,0x28AED2A6,0xABF71588,0x09CF4F3C};
    unsigned long long WW[] = {0x0,0x0,0x0,0x0};
    unsigned long long w0 = 0x7c636363;
    unsigned long long w1 = 0x63636363;
    printf("%llx ",w0^W[0]);
    for(int i=0;i<3;i++)
        printf("%llx jiehsu\n",w1^WW[i]);
    unsigned long long W1[] = {0x01000000,0x0,0x0,0x0};
    for(int i=0;i<4;i++)
        printf("\n%llx :end\n",W[i]^W1[i]);
    unsigned long long W4[] ={0x54f65544,0x7c34569d,0x363d3ca2,0x3e133486};
    unsigned long long W5[] = {0xA0FAFE17,0x88542CB1,0x23A33939,0x2A6C7605};
    for(int i=0;i<4;i++)
        printf("%llx abc\n",W4[i]^W5[i]);
    return 0;
}