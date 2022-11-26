#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s){
        unordered_map<char, int> count;
        int ans = 0;
        for(char c : s)
            ++count[c];
        for(auto p : count){
            int v = p.second;
            ans += v / 2 * 2;
            if(v % 2 == 1 && ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};