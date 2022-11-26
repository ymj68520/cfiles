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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return(builder(preorder,0,preorder.size(),inorder,0,inorder.size()));
    }
    // 3,9,20,15,7  preorder
    // 9,3,15,20,7  inorder
    TreeNode* builder(vector<int>& preorder,int p_start, int p_end, 
                      vector<int>& inorder, int i_start, int i_end){
        if(p_start == p_end) return nullptr;
        int rootVal = preorder[p_start];
        TreeNode *root = new TreeNode(rootVal);
        int index = i_start;
        for(int i=i_start;i<i_end;i++){
            if(rootVal == inorder[i]){
                index = i;
                break;
            }
        }
        int left = index - i_start;
        root->left = builder(preorder,p_start+1,p_start+left+1,inorder,i_start,index);
        root->right= builder(preorder,p_start+left+1,p_end,inorder,index+1,i_end);
        return root;
    }
};