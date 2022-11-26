#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long minLimit, long maxLimit){
        if(root == nullptr) return true;
        if(root->val >= maxLimit || root->val <= minLimit)
            return false;
        return isValidBST(root->left,minLimit,(long)root->val) && isValidBST(root->right,(long)root->val,maxLimit);
    }
};

int main(){
    
}