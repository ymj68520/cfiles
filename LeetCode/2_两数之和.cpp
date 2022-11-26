/**
 * 给你两个 非空 的链表，表示两个非负的整数。
 * 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 */
#include <iostream>
#include <cstdlib>
// 表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *L,*p=l1,*q=l2,*r;
    L = new ListNode;
    r = L;
    int flag(0);
    while(p != nullptr || q != nullptr || flag){
        int temp;
        if(!p && !q && flag){
            temp = flag;
        }
        else if(p && q){
            temp = p->val + q->val + flag;
            p=p->next;q=q->next;
        }
        else if(p){
            temp = p->val + flag;
            p=p->next;
        }
        else if(q){
            temp = q->val + flag;
            q=q->next;
        }
        if(temp>9){
            flag = 1;
            temp -= 10;
        }
        else
            flag = 0;
        ListNode *s = new ListNode;
        *s = ListNode(temp);
        r->next = s;
        r = r->next;
        // flag = false;
    }
    return L->next;
}