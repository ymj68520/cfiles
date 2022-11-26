/*
    The input is composed of several lines, each containing 4 integers separated by a single space. 
    The 4 integers represent the distances of each object to the fulcrum and their weights, 
    in the format:  Wl Dl Wr Dr

    If Wl or Wr is zero then there is a sub-mobile hanging from that end and the following lines 
    define the the sub-mobile. 
    In this case we compute the weight of the sub-mobile as the sum of weights of all its objects, 
    disregarding the weight of the wires and strings. 
    If bothWl andWr are zero then the following lines define two sub-mobiles: 
    first the left then the right one.

    一行四个整数W1 D1 Wr Dr，当W（权重）为0表示此处是一个子天平（即为子树）[先序输入二叉树！]
    输入为递归式的，因此解决为递归式的。
        递归式，优先左子树，一直递归至最左子树，优先解决最左子树，退出最左子树时，最左子树是否平衡已经得出
        b1 ？= true;
    当有一个子天平不平衡时，整个天平即为不平衡。
*/

#include <iostream>
using namespace std;

bool solve(int &W){ // W为本次solve函数处理的天平总权重
    int W1,D1,W2,D2;
    bool b1 = true, b2 = true;
    cin >> W1 >> D1 >> W2 >> D2;
    if(!W1) b1 = solve(W1);
    if(!W2) b2 = solve(W2);
    W = W1 + W2;
    return b1 && b2 &&(W1*D1 == W2*D2);
}
int main(){
    int T,W;    // 测试数据组数、每组数据的总权重
    cin >> T;
    while(T--){
        if(solve(W)) cout << "YES\n";   // main函数的W仅为辅助，每次在solve中计算子天平的总权重
        else cout << "NO\n";
        if(T)   cout << '\n';
    }
    return 0;
}