#include <cstdio>
using namespace std;
int main(){
    typedef unsigned long long ll;
    ll c1[] ={0xf40cab53,0xf4607a2c,0x159e059b,0x147f4283};
    ll c10[]={0x01000000,0x00000000,0x00000000,0x00000000};
    ll c2[] ={0x63636363,0x63636363,0x63636363,0x63636363};
    ll c20[]={0x00000000,0x00000000,0x00000000,0x00000000};
    printf("\nc1^c10 = \n");
    for(int i=0;i<4;i++)
        printf("%llx\n",c1[i]^c10[i]);

    printf("\nc1^c2 = \n");
    for(int i=0;i<4;i++)
        printf("%llx\n",c1[i]^c2[i]);

    printf("\nc2^c20 = \n");
    for(int i=0;i<4;i++)
        printf("%llx\n",c2[i]^c20[i]);
}