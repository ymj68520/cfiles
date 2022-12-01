#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int cnt;
    vector<int> path;
    void dfs(TreeNode *root){
        if(root == nullptr) return;

        if(check(root->val))    cnt++;
        path.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
    }
    bool check(int val){
        for(auto &x : path) if(x > val)
            return false;
        return true;
    }
public:
    int goodNodes(TreeNode* root) {
        cnt = 0;
        path.clear();
        dfs(root);
        return cnt;
    }
};
