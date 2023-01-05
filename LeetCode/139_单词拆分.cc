#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

bool wordBreak(string s,set<string>wordDict){
    int len = s.length();
    int dp[len+1];memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=len;i++){
        for(int j=0;j<i;j++){
            if(dp[j] && wordDict.count(s.substr(j,i)))  dp[i] = true;
        }
    }
    return dp[len];
}

class Trie {
public:
	Trie *children[26];
	bool is_word;
    void insert(string word) {
		Trie *node = this;
		for (char c : word) {
			c -= 'a';
			if (!node->children[c]) node->children[c] = new Trie();
			node = node->children[c];
		}
		node->is_word = true;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		Trie *root = new Trie(), *node;
		for(string &word : wordDict)    root->insert(word);
		int n = s.size();
		vector<bool> dp(n + 1); //dp[i]表示s[i,n-1]能否由词典单词拆分
		dp[n] = true;
		for(int i = n - 1; i >= 0; --i) { //倒序计算，依次判断s[i,n-1]能否由词典单词拆分
			node = root;
			for (int j = i; j < n; j++) {
				char c = s[j];
				node = node->children[c - 'a'];
				if (!node) break; //s[i,j]不是词典中的单词，j往后递增也不可能是
				if (node->is_word && dp[j + 1]) { //s[i,j]是词典中的单词，且s[j+1,n-1]能由词典单词拆分
					dp[i] = true; break; //则s[i,n-1]能由词典单词拆分
				}
			}
		}
		return dp[0];
    }
};

int main(){
    string s = "LeetCodeLeet";
    set<string> words = {"leet","Code","Leet"};
    cout << wordBreak(s,words) << endl;

    return 0;
}