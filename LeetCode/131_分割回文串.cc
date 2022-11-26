#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    
    vector<vector<string> > ans;
    bool ishwstring(int start, int end, const string &s){
        while(start < end)
            if(s[start++] != s[end--])  
                return false;
        return true;
    }
    void dfs(const string &s,int start, vector<string> &path){
        if(start >= s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=start;i<s.length();++i){
            if(!ishwstring(start,i,s))  continue;
            path.push_back(s.substr(start,i-start+1));
            dfs(s,i+1,path);
            path.pop_back();
            
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> path;
        dfs(s,0,path);
        return ans;

    }
};

class Solution1{
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        vector<string> tmp;
        run(0,s,tmp,r);
        return r;
    }

    bool ishwstring(int start, int end, const string &s){
        while(start < end)
            if(s[start++] != s[end--])  
                return false;
        return true;
    }

    void run(int index, string s, vector<string> &tmp, vector<vector<string>> &r) {
        if(index>=s.size()) { //分割完保存
            r.push_back(tmp);
            return;
        }

        for(int i=index;i<s.size();i++) { 
            if(!isVaild(s, index, i)) continue; // 减枝
            auto str = s.substr(index, i-index+1); // 因为需要长度所以要 +1
            tmp.push_back(str);
            run(i+1,s,tmp,r);
            tmp.pop_back();
        }
    }

    bool isVaild(string &s, int start, int end) { 
        while(end>start) {
            if(s[start] != s[end]) {return false;}
            end--;
            start++;
        }
        return true;
    }
};

int main(){
    string s = "aba";
    vector<vector<string> > ans;
    Solution sol;
    ans = sol.partition(s);
    for(auto x : ans){
        for(auto y:x){
            for(auto z:y)   cout << z;
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution1 sol1;
    ans = sol1.partition(s);
    for(auto x : ans){
        for(auto y:x){
            for(auto z:y)   cout << z;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}