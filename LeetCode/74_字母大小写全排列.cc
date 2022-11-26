#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    set<string> cnt;
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solver(ans,s,0);
        return ans;
    }
    void solver(vector<string> &ans, string& s, int pos){
        if(pos  == s.length()){
            ans.push_back(s);
            return;
        }
        solver(ans,s,pos+1);
        if(s[pos]>'9'){
            s[pos] ^= ' ';
            solver(ans,s,pos+1); 
        }
    }
};

int main(){
    string s = "ab";
    Solution sol;
    vector<string> ans = sol.letterCasePermutation(s);
    for(auto str : ans){
        for(auto ch:str)    cout << ch;
        cout << endl;
    }
}