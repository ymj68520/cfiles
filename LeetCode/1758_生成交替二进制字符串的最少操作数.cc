#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(n == 1)  return 0;
        int cnt=0;
        for (int i = 0; i < n; i++) cnt += (s[i] - '0') ^ (i & 1);
        return min(cnt,n-cnt);
    }
};

int main(){
    string s = "01001111111";
    Solution sol;

    cout << sol.minOperations(s) << endl;

    return 0;
}