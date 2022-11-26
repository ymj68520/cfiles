#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    enum keys {type, color, name};
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key=0;
        if(ruleKey == "type")   key = type;
        else if(ruleKey == "color") key = color;
        else key = name;
        int cnt(0);
        for(auto x:items)
            if(x[key] == ruleValue) cnt++;
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> items = {{"phone","blue","pixel"},
                                    {"computer","silver","lenovo"},
                                    {"phone","gold","iphone"}};
    string rule = "color";
    string ruleVal = "silver";

    cout << sol.countMatches(items,rule,ruleVal) <<endl;
}