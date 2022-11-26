#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    set<int> st;
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        st.insert(head->val);
        ListNode *p = head->next;
        ListNode *q = head;
        while(p != nullptr){
            if(st.count(p->val) == 0){
                st.insert(p->val);
                q = p;
                p = p->next;
            }
            else{
                p = p->next;
                q->next = p;
            }
        }
        return head;
    }
};