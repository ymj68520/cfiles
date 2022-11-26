#include <iostream>
using namespace std;

int cnt = 0;
int S[1111] = {0};   // 使用数字（ASCII码，相对于‘A’的距离）表示每一个字母
int n=0,L=0;

bool search(int cur){
    if(cnt++ == n){
        for(int i=0; i<cur;i++) printf("%c",'A'+S[i]);
        printf("\n");
        return true;    // 已经找到了第N个解
    }
    for(int i=0; i<L; i++){
        S[cur] = i;
        int ok = 1;
        for(int j=1; j*2<=cur+1; j++){
            int eql = 1;
            for(int k=0; k<j; k++) if(S[cur-k] != S[cur-k-j]){
                eql = 0; break;
            }
            if(eql){ok=0; break;}
        }
        if(ok)  if(!search(cur+1))  return true;
    }
    return false;
}

int main(){
    n=930;
    L=4;
    search(0);

    return 0;
}
