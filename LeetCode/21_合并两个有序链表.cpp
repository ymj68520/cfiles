/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 终止条件，判断两个链表是否为空链表
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        // 定义一个空链表，存放合并后的节点
        ListNode *res = nullptr;
        // res = list1->val < list2->val ? list1 : list2;
        // res->next = list1->val < list2->val ? mergeTwoLists(list1->next, list2) : mergeTwoLists(list1, list2->next);
        if (list1->val < list2->val) {
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        } else {
            res = list2;
            res->next = mergeTwoLists(list1, list2->next);
        }

        return res;
}