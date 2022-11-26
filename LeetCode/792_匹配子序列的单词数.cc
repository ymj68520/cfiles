#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int state[n];memset(state,0,sizeof(state));
        for(auto & ch : s){
            for(int i=0;i<words.size();++i){
                if(words[i][state[i]] == ch)   state[i]++;   
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)    if(state[i]==words[i].length())
            cnt ++;
        return cnt;
    }
    int numMatchingSubseq2(string s, vector<string>& words) {
        vector<queue<pair<int,int> > > d(26);
        for (int i = 0; i < words.size(); ++i) d[words[i][0] - 'a'].emplace(i, 0);
        int ans = 0;
        for (char& c : s) {
            auto& q = d[c - 'a'];
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                if (++j == words[i].size()) ++ans;
                else d[words[i][j] - 'a'].emplace(i, j);
            }
        }
        return ans;
    }
};


int main(){
    vector<string> w = {"qlhxagxdq","qlhxagxdq","lhyiftwtut","yfzwraahab"};
    string s = "qlhxagxdqh";

    Solution sol;
    cout << sol.numMatchingSubseq(s,w) << endl;

    return 0;
}