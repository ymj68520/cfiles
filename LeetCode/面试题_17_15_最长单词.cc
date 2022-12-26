#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        if(n<2) return "";
        unordered_map<char, vector<string> > map;
        for(auto &s : words)    map[s[0]].push_back(s);
        string ans = "";
        auto dfs = [&](auto && dfs, char cur, string target)->bool{
            bool t = false;
            for (auto &s : map[cur]){
                if(s.size()==target.size() && s == target)  return true;
                else if(s.size() < target.size() && target.substr(0,s.size())==s){
                    if(dfs(dfs,target[s.size()],target.substr(s.size()))){
                        t = true;
                        break;
                    }
                }
            }
            return t;
        };
        for (auto &s : words){
            if(ans.size() > s.size())   continue;
            for(auto &t : map[s[0]]){
                if(t.size() < s.size() && s.substr(0,t.size()) == t && dfs(dfs,s[t.size()],s.substr(t.size()))){
                    ans = ans.size()==s.size() ? (ans<s ? ans : s) : s;
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){
    string s1 = "ab";
    string s2 = "a";
    vector<string> ws;
    ws.push_back("bcd");
    ws.push_back(s1);
    ws.push_back(s2);
    ws.push_back("cbd");
    sort(ws.begin(),ws.end());
    // bool f = (s2 == s1.substr(0,s2.length()));
    for(string &s : ws){
        cout << s << endl;
    }

    return 0;
}