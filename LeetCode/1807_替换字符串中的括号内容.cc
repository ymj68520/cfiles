#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &k)
    {
        unordered_map<string, string> mp;
        for (auto &t : k)
            mp[t[0]] = t[1];
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                string item;
                while (s[++i] != ')')
                    item += s[i];                       // 截取()之间的字符
                ans += mp.count(item) ? mp[item] : "?"; // 若不存在添加?
            }
            else
                ans += s[i];
        }
        return ans;
    }
};