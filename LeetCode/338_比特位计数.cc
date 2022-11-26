#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
vector<int> countBits(int n) {
    vector<int> ret(n+1,0);
    ret[0] = 0;
    for(int i=1;i<=n;i++){
        if(i%2) ret[i] = ret[i-1]+1;
        else    ret[i] = ret[i/2];
    }
    return ret;
}
int main(){
    vector<int> ans = countBits(5);
    for(auto& x:ans)    cout << x << " ";
    cout << endl;
    return 0;
}