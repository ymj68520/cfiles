#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int L=0;
    ListNode *dummy = new ListNode(0,head);
    ListNode *p = head;
    while(p){
        L++;
        p=p->next;
    }
    p = dummy;
    for(int i=1;i<L-n+1;i++)
        p = p->next;
    p->next = p->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;    
}