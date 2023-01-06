#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Trie{
public:
    Trie *next[26];
    bool isWord;
    Trie(){
        isWord = false;
        memset(next,0,sizeof(next));
    }
    void insert(const string &str){
        Trie *node = this;
        for(const char &c : str){
            int u = c-'a';
            if(node->next[u] == nullptr)    node->next[u] = new Trie;
            node = node->next[u];
        }
        node->isWord = true;
    }
    bool query(const string & str, Trie *p, int start){
        if(p == nullptr)    return false;
        if(start == str.size()) return p->isWord;
        char c = str[start];
        if(c != '.'){
            return query(str,p->next[c-'a'],start+1);
        }
        else{
            for(const auto &child : p->next){
                if(query(str,child,start+1))    return true;
            }
        }
        return false;
    }
    
};

class WordDictionary {
    Trie *trie;
public:
    WordDictionary() {
        trie = new Trie;
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->query(word, trie, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */