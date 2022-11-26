#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

void dfs(const string &digits, string curs, const int &n, int cnt);

string smap[10];
vector<string> ans;

vector<string> letterCombinations(string digits) {
    if(digits.empty())  return ans;

    smap[2] = "abc";
    smap[3] = "def";
    smap[4] = "ghi";
    smap[5] = "jkl";
    smap[6] = "mno";
    smap[7] = "pqrs";
    smap[8] = "tuv";
    smap[9] = "wxyz";

    int n = digits.size();
    string curs;
    dfs(digits, curs, n, 0);
    return ans;
}
void dfs(const string &digits, string curs, const int &n, int pos_n){
    if(curs.size() == n){
        ans.push_back(curs);
        return;
    }
    int pos = digits[pos_n] - '1' + 1;
    for(int i=0;i<smap[pos].length();i++){
        curs.push_back(smap[pos][i]);
        dfs(digits,curs,n,pos_n+1);
        curs.pop_back();
    }
}

int main(){
    string dig = "2345";
    vector<string> ans = letterCombinations(dig);
    for(auto x:ans){
        for(auto y:x){
            cout << y;
        }
        cout << " ";
    }
    cout <<endl;
}