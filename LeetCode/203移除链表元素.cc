#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(!head){
        return head;
    }
    head->next = removeElements(head->next , val);  // 先深入递归，从结尾开始删除
    if(head->val == val){
        ListNode* t = head->next;
        delete head;
        return t;
    }
    return head;
}