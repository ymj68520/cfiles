#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    unordered_map<int, ListNode*> ma;
    int cnt = 0;
    while (head) {
        ma[cnt++] = head;
        head = head->next;
    }
    head = ma[0];  // head归位
    int l = 1, r = cnt - 1;  // 待指定
    bool front = false;
    while (l <= r) {
        if (front) {
            head->next = ma[l++];
            front = false;
        }
        else {
            head->next = ma[r--];
            front = true;
        }
        head = head->next;
    }
    head->next = nullptr;  // 最后一个节点的next置空
}
