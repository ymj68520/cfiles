#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 随手先来个暴力解
ListNode* mergeKLists1(vector<ListNode*>& lists) {
    if(lists.empty())   return nullptr;
    vector<int> temp;
    for(auto list : lists){
        while(list){
            temp.push_back(list->val);
            list = list->next;
        }
    }
    sort(temp.begin(),temp.end());
    ListNode * ans = new ListNode;
    ListNode * dummy = new ListNode(0,ans);
    for(auto x:temp){
        ans->val = x;
        ans->next = new ListNode;
        ans = ans->next;
    }
    return dummy->next;
}

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
// 两两合并
ListNode* mergeKLists2(vector<ListNode*>& lists) {
    ListNode *res = nullptr;
    for(auto list : lists){
        res = mergeTwoLists(res,list);
    }
    return res;
}

// 分治法
ListNode *mergeList(vector<ListNode*>& lists,int low,int high);
ListNode* mergeKLists(vector<ListNode*>& lists){
    if(lists.size()==0) return nullptr;

    return mergeList(lists,0,lists.size()-1);
}
ListNode *mergeList(vector<ListNode*>& lists,int low,int high){
    if(low == high)
        return lists[low];

    int mid = (low+high)/2;
    ListNode *L1 = mergeList(lists,low,mid);
    ListNode *L2 = mergeList(lists,mid+1,high);
    return mergeTwoLists(L1,L2);
}