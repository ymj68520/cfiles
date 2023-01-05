#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int N = 11111;

int trie[N][26], cnt[N], idx;
void insert(string str){
    int p = 0;
    for (int i = 0; i < str.length(); i++){
        int u = str[i] - 'a';
        if (!trie[p][u]) trie[p][u] = ++ idx;//创建结点并赋予编号idx
        p = trie[p][u];//走到下一个结点
    }
    cnt[p]++ ;//个数增加
}

int query(string str){
    int p = 0;
    for (int i = 0; i < str.length(); i++){
        int u = str[i] - 'a';
        if (!trie[p][u]) return 0; //若当前结点不存在，那么直接返回0
        p = trie[p][u];
    }
    return cnt[p];//返回存在的次数
}
