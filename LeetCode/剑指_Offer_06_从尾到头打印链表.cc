#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "LeetCodeListNode.h"

using namespace std;

class Solution1 {
    vector<int> ans;
    void helper(ListNode *root){
        if(root == nullptr) return;
        ans.emplace(ans.begin(),root->val);
        helper(root->next);
    }
public:
    vector<int> reversePrint(ListNode* head) {
        helper(head);
        return ans;
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head -> val);
            head = head -> next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};