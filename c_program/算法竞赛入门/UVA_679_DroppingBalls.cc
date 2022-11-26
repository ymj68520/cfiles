#include <iostream>
#include <cstring>
#include <cassert>
const int  maxd = 20;
int s[1 << maxd]; // 2^(maxd) - 1
int main(){
    int D,I;
    while(1){
    assert(scanf("%d %d",&D,&I)==2);
    // 一般方法 运算量大
    /*while(scanf("%d %d",&D,&I)==2){*/
        memset(s,0,sizeof(s));      // 开关
        int k,n=(1<<D)-1;       // n为最大节点编号
        for(int i=0;i<I;i++){
            k=1;
            for(;;){
                s[k] = !s[k];
                k = s[k]?k*2:k*2+1;
                if(k>n) break;
            }
        }
        printf("%d\n",k/2); // 出界之前的编号，不论左右叶子除二均为父节点
    /*}*/
    /*
        快速方法
        每个小球落在根节点 前两个必然一个左子树一个右子树
        依次类推
        当I为奇数时 它为往左走的第（I+1)/2个小球
        当I为偶数是 它为往右走的第 I/2 个小球
        直接模拟最后一个小球
    */
    /*while(scanf("%d %d",&D,&I)==2){*/
        /*int*/ k=1;
        for(int i=0;i<D-1;i++)
            if(I%2){k=k*2;I=(I+1)/2;}
            else {k = k*2+1;I/=2;}
        printf("%d\n",k);
    /*}*/
    }
    return 0;
}
