#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
private:
    vector<string> result;
    void backtracking(string &s, int start, int pointNum){
        if(pointNum == 3){  // 已经插满小数点 回溯
            if(isValid(s,start,s.size()-1)) return result.push_back(s);
            return;
        }
        for(int i=start;i<s.size();++i){       // 递归分割
            if(isValid(s,start,i)){
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                backtracking(s,i+2,pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }
            else    break;
        }
    }
    bool isValid(const string &s, int start, int end){
        if(start > end) return false;   // 范围非法
        if(s[start]=='0' && start!=end) return false; // 以0开头的不合法
        int num=0;
        for(int i=start;i<=end;i++){
            if(s[i]>'9' || s[i]<'0')    return false;   // 非数字
            num = num * 10 + (s[i]-'0');
            if(num > 255)   return false;   // 超过最大表示范围
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size()>12) return result;
        backtracking(s,0,0);
        return result;
    }
};

int main(){
    string s = "255255255255";
    Solution sol;
    vector<string> ans = sol.restoreIpAddresses(s);
    for(auto &str:ans){
        for(auto &ch:str)   cout << ch;
        cout << endl;
    }

    return 0;
}