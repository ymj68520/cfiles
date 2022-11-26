#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void intral(vector<int> &ans,TreeNode* root){
    if(!root)   return;
    intral(ans, root->left);
    ans.push_back(root->val);
    intral(ans, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    intral(ans,root);
    return ans;
}