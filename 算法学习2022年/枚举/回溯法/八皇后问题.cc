// 每行每列必定有且仅有一个皇后
// 使用c[x]表示第x行皇后的列编号。

/*
 * 回溯：
 * 当把问题分为若干步骤递归求解时，若当前步骤没有合法选择，
 * 则函数将返回上一级调用。
 * 
 * 八皇后问题：
 *  因为皇后行动范围为 同行 同列 两个对角线，
 *  由于皇后的同行同列性，导致逐行选择性的放入皇后；
 *  因此，解决问题的方法就可以从直接枚举退化为排列问题。
 *  
 *  现在，主要需要解决的方面为对角线判断，根据每个点的横纵坐标差和坐标和相等，
 *  可以确定两个点是否在同一对角线上！
 *  例如：
 *   这是y-x：            x+y:
 *  0  1  2  3          0 1 2 3
 * -1  0  1  2          1 2 3 4
 * -2 -1  0  1          2 3 4 5
 * -3 -2 -1  0          1 4 5 6
 */
#include <iostream>
using namespace std;

static int tot=0;
static int n=0;
int C[11] = {0};
void search(int cur){
    if(cur == n)    tot++;
    else for(int i=0;i<n;i++){
        int ok=1;
        C[cur] = i;
        for(int j=0;j<cur;j++)
            if(C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j])
            { ok = 0; break;}
        if(ok) search(cur+1);
    }
    return;
}
// 使用数组直接判定之前的皇后使用了那些行列及对角线
void search2(int cur){

}

int main(){
    n = 8;
    search(0);
    printf("%d\n",tot);

    return 0;
}