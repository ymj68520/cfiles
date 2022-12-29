#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int p=0,q=n-1;
        while(p<q && s[p] == s[q]){
            while(p<q && s[p] == s[p+1])   p++;
            while(q>p && s[q] == s[q-1])   q--;
            p++;q--;
        }
        if(p > q)  return 0;
        return q-p+1;
    }
};

int main(){
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution sol;
    cout << sol.minimumLength(s) << endl;
}