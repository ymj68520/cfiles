// 有问题 没修改

#include <iostream>
#include <queue>
using namespace std;

int cnt=0;double sum=1;int fl=2;
queue<int> A;
void Tobinaty(int n){
    int a;
    a = n%2;
    n = n >> 1;
    if(n==0)    fl--;
    if(n>=0 && fl){
        A.push(a);
        Tobinaty(n);
    }
}
void solver(double x){
    if(A.empty()) return;
    int t = A.front();A.pop();
    sum += sum*x*t;
    solver(sum);
}
double myPow(double x, int n) {
    int flag = (n<0)?0:1;
    n = (n<0)?(0-n):n;
    Tobinaty(n);
    solver(x);
    
    if(flag)    return sum;
    else    return 1/sum;
}

int main(){
    cout << myPow(3,2) << endl;

    return 0;
}