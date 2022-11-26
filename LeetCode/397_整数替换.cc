#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
int dfs(long);
unordered_map<long,int> mmp;
int integerReplacement(int n) {
    return dfs((long)n);
}
int dfs(long n){
    if(n==1)    return 0;
    if(mmp.count(n))    return mmp[n];
    int ans = n%2==0 ? dfs(n/2) : min(dfs(n+1),dfs(n-1));
    mmp[n] = ++ans;
    return ans;
}
int integerReplacement2(int n) {
    long m = n;
    int cnt=0;
    while(m!=1){
        if(m%2){
            long temp = m-1;
            if(!(temp/2) && temp/2 % 2)
                m = m+1;
            else
                m = temp;
        }
        else
            m /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    int n = 123;
    cout << integerReplacement(n) << endl << integerReplacement2(n)<<endl;

    return 0;
}