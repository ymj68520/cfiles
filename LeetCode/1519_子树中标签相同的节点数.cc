#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
class Solution 
{
public:
    vector<vector<int>> adjvex;     //邻接矩阵
    vector<vector<int>> subtree;    //子树中（含自己）每个字母的个数

    void dfs(int rt, int pre, const string & labels)
    {
        subtree[rt][labels[rt] - 'a'] = 1;
        for (int child: adjvex[rt])
        {
            if (child == pre)           //邻接矩阵是无向图   而题目有向
                continue;
            dfs(child, rt, labels);
            for (int c=0; c<26; c++)                //这个操作有点像dfs实现拓扑排序  后处理 孩子们都干好了，我再动手
                subtree[rt][c] += subtree[child][c];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        adjvex.resize(n);
        subtree.assign(n, vector<int>(26, 0));
        for (const auto &v: edges)
        {
            adjvex[v[0]].push_back(v[1]);
            adjvex[v[1]].push_back(v[0]);
        }

        dfs(0, -1, labels);

        vector<int> res;
        for (int i=0; i<n; i++)
        {
            res.push_back(subtree[i][labels[i] - 'a']);
        }
        return res;
    }
};
*/
class Solution {
private:
    vector<vector<int> > adjvex;    // 邻接矩阵
    vector<vector<int> > subtrees;  // 子树中（包含自己）每个字母的个数

    void dfs(int rt, int pre, const string &labels){
        subtrees[rt][labels[rt]-'a'] = 1;
        for(int child : adjvex[rt]){
            if(child == pre) continue;
            dfs(child, rt, labels);
            for(int c=0; c<26; ++c)
                subtrees[rt][c] += subtrees[child][c];
        }
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adjvex.resize(n);adjvex.clear();
        subtrees.assign(n,vector<int>(26,0));
        for(const auto &v : edges){
            adjvex[v[0]].push_back(v[1]);
            adjvex[v[1]].push_back(v[0]);
        }
        dfs(0,-1,labels);

        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(subtrees[i][labels[i]-'a']);

        return ans;
    }
};