#include <iostream>
using namespace std;

int StateMatrix[4][4];  // 状态矩阵

int muti(int hex1, int hex2){
    switch(hex1){
        case 0x01:
            return hex2;
        case 0x02:
            if(hex2 >= 0x80){
                hex2 = hex2 << 1;
                hex2 = hex2 % 32;
                hex2^= 0x1b;
            }
            else{
                hex2 = hex2 << 1;
                //hex2 = hex2 %16;
            }
            return hex2;
        case 0x03:
            return muti(0x01,hex2) ^ muti(0x02,hex2);
    }
    printf("出错啦！");
    return -1;
}

int main(){
    int input;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            cin >> hex >> input;        // 以16进制读取状态矩阵。
            StateMatrix[i][j] = input;
        }
    int d0,d1,d2,d3;
    for(int i=0;i<4;i++){
        d0 = muti(0x02,StateMatrix[0][i]) ^ muti(0x03,StateMatrix[1][i]);
        d0^= muti(0x01,StateMatrix[2][i]) ^ muti(0x01,StateMatrix[3][i]);

        d1 = muti(0x01,StateMatrix[0][i]) ^ muti(0x02,StateMatrix[1][i]);
        d1^= muti(0x03,StateMatrix[2][i]) ^ muti(0x01,StateMatrix[3][i]);

        d2 = muti(0x01,StateMatrix[0][i]) ^ muti(0x01,StateMatrix[1][i]);
        d2^= muti(0x02,StateMatrix[2][i]) ^ muti(0x03,StateMatrix[3][i]);

        d3 = muti(0x03,StateMatrix[0][i]) ^ muti(0x01,StateMatrix[1][i]);
        d3^= muti(0x01,StateMatrix[2][i]) ^ muti(0x02,StateMatrix[3][i]);

        printf("第%d列的结果是：\n%x %x %x %x\n",i,d0,d1,d2,d3);   
        StateMatrix[0][i] = d0;
        StateMatrix[1][i] = d1;
        StateMatrix[2][i] = d2;
        StateMatrix[3][i] = d3;
    } 
    return 0;
}
/*
e5 f3 59 47
e4 b5 24 34
59 c4 62 68
eb 01 8a 84
*/