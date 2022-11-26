#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
    if(n<3 || n%3!=0) return false;
    if(n==3)    return true;
    return isPowerOfThree(n/3);
}

int main(){
    int n;
    while(1){
        cout << "请输入：" ;
        cin >> n;
        cout << isPowerOfThree(n) << endl;
    }
    return 0;
}