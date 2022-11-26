#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    
    string customSortString(string order, string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        string ans;
        for (char& c : order) while (cnt[c - 'a']-- > 0) ans += c;
        for (int i = 0; i < 26; ++i) if (cnt[i] > 0) ans += string(cnt[i], i + 'a');
        return ans;
    }
};

int main(){
    string ord = "cba";
    string s = "abcd";
    Solution sol;

    string ans = sol.customSortString(ord,s);
    for(auto x:ans) cout << x;
    cout << endl;

    return 0;
}