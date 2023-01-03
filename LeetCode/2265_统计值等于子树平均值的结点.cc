#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include "LeetCodeTree.h"

using namespace std;

class Solution {
    int ans,cnt;
    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        int cur = cnt;
        cnt++;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        if(sum/(cnt - cur) == root->val)    ans++;
        return sum;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans=0,cnt=0;;
        dfs(root);
        return ans;        
    }
};
