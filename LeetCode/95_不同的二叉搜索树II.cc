#include <iostream>
#include <vector>
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
public:
    vector<TreeNode*> generateTrees(int start, int end){
        if(start > end) return vector<TreeNode*>{nullptr};
        vector<TreeNode *> trees;
        for(int i=start;i<=end;++i){
            vector<TreeNode*> ltrees=generateTrees(start,i-1),rtrees=generateTrees(i+1,end);
            for(auto &left : ltrees){
                for(auto &right : rtrees){
                    TreeNode* curTree = new TreeNode(i);
                    curTree->left = left;
                    curTree->right = right;
                    trees.emplace_back(curTree);
                }
            }
        }
        return trees;

    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)    return vector<TreeNode*>{nullptr};
        return generateTrees(1,n);
    }
};