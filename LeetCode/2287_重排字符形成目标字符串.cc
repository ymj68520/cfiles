#include "LeetCode.h"

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int map[26]{0},ans=INT_MAX;
        unordered_map<int,int> mp;
        for(char &c : s)    map[c-'a']++;
        for(char &c : target) mp[c-'a']++;
        for(auto &n : mp)   map[n.first]/=n.second;
        for(auto &n : mp)   ans = min(ans,map[n.first]);
        return ans;
    }
};