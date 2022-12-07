#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int deep(TreeNode *root){
        if(root == nullptr) return 0;
        int left = deep(root->left);
        int right= deep(root->right);

        if(left==-1 || right==-1 || abs(left-right)>1)  return -1;

        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return deep(root) != -1;
    }
};