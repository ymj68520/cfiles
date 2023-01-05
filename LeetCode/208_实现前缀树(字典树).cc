#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Trie {
    static const int N = (int)3e4;
    int node[N][26],cnt[N],indx;
public:
    Trie() {
        memset(node,0,sizeof(node));
        memset(cnt,0,sizeof(cnt));
        // bzero(cnt,sizeof(cnt));  // 能使，为了取消warning
        indx=0;
    }
    
    void insert(string word) {
        int p=0;
        for(int i=0; i<word.size(); ++i){
            int u = word[i] - 'a';
            if(!node[p][u]) node[p][u] = ++indx;
            p = node[p][u];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        for(int i=0; i<word.size(); ++i){
            int u = word[i] - 'a';
            if(!node[p][u]) return false;
            p = node[p][u];
        }
        return cnt[p] != 0;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(int i=0; i<prefix.size(); ++i){
            int u = prefix[i] - 'a';
            if(!node[p][u]) return false;
            p = node[p][u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */