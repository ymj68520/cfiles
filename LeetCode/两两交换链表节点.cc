#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head->next == nullptr || head == nullptr)   return head;
    ListNode *cur,*next;
    cur = head->next;
    next = cur->next;
    cur->next = head;
    head->next = swapPairs(next);
    return cur;
}