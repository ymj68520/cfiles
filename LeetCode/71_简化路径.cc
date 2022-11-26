#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string &s, char delim) -> vector<string> {
            vector<string> res;
            string cur;
            for(auto c :s){
                if(c == delim){
                    res.push_back(cur);
                    cur.clear();
                }
                else{
                    cur += c;
                }
            }
            if(!cur.empty()){
                res.push_back(cur);
            }
            return res;
        };
        vector<string> names = split(path,'/');
        vector<string> sk;
        for(auto &name : names){
            if(name.empty() || name == "."){
                continue;
            }
            else if(name != ".."){
                sk.push_back(name);
            }
            else{
                if(!sk.empty())
                    sk.pop_back();
            }
        }
        string ans;
        for(auto &name : sk){
            ans += "/" + name;
        }
        if(ans.empty()){
            ans = "/";
        }
        return ans;
    }
};