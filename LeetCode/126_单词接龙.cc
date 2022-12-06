#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
       
    unordered_set<string> words;

    //判断节点是否直连
    bool connect(const string &s1, const string &s2)
    {
        int n = s1.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
            {
                cnt++;
                if(cnt > 1) return false;
            }
        }
        return cnt == 1;
    }

    //返回从某一层节点集合startSet到endWord的路径集合
    vector<vector<string>> findPath(unordered_set<string> &startSet, string &end)
    {
        int num = startSet.size();
        unordered_set<string> nbSet; //下一层节点集合
        vector<vector<string>> ret;
        if(num == 0) return ret; //起始节点集合为空，递归结束
        
        for(auto &t:startSet) //求下一层节点集合
        {
            for(int j = 0; j < t.size(); j++)
            {
                for(char c='a'; c <= 'z'; c++)
                {
                    if(c == t[j]) continue;
                    string temp = t;
                    temp[j] = c;
                    if(temp == end) //如果下一层节点中包含endWord，记录该路径
                    {
                        ret.push_back(vector<string>{t, end});
                    }
                    if(words.count(temp) != 0 && nbSet.count(temp) == 0) nbSet.insert(move(temp));
                }
            }
        }
        
        //如果下一层节点中包含endWord，递归结束
        if(nbSet.count(end) > 0) return ret; 
        
        //遍历过的节点不再遍历
        for(auto &it:nbSet) words.erase(it);
        
        auto nbPathSet = findPath(nbSet, end); //递归调用
        for(auto &itNb : nbPathSet) //构建本层到end的路径
        {
            for(auto &itStart : startSet)
            {
                if(connect(itNb[0], itStart))
                {
                    vector<string> path{itStart};
                    path.insert(path.end(), itNb.begin(), itNb.end());
                    ret.push_back(move(path));
                }
            }
        }
        return ret;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        for(auto &it: wordList) words.insert(it); //构建hash表
        if(words.count(endWord) == 0) return ret;
        words.erase(beginWord);

        unordered_set<string> startSet;
        startSet.insert(beginWord); //startWord作为第一个节点集合
        
        return findPath(startSet, endWord);
    }
};

int main(){
    vector<string> ws = {"hot","dot","dog","lot","log","cog"};
    string b = "hit";
    string e = "cog";
    Solution sol;
    
    auto ans = sol.findLadders(b,e,ws);
    for(auto &x : ans){
        for(auto &y : x)    cout << y << " ";
        cout << endl;
    }
    cout << endl;
}