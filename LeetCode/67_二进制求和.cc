#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string ret = "";
    int i = a.length()-1;
    int j = b.length()-1;
    int carry = 0;
    while(i>=0 && j>=0){
        int sums = a[i] + b[j] - '0' - '0' + carry;
        carry = sums/2;
        sums %= 2;
        ret.push_back('0'+sums);
        i--;j--;
    }
    while(i>=0){
        int sums = a[i] + carry -'0';
        carry = sums/2;
        sums %= 2;
        ret.push_back('0'+sums);
        i--;
    }
    while(j>=0){
        int sums = b[j] + carry -'0';
        carry = sums/2;
        sums %= 2;
        ret.push_back('0'+sums);
        j--;
    }
    if(carry)
        ret.push_back('0'+1);
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    string s1,s2,ans;
    s1 = "1";
    s2 = "111";
    ans = addBinary(s1,s2);
    for(auto s:ans) cout << s;
    cout <<endl;

    return 0;
}