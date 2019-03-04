#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int curr = -1;
        ListNode *ret = new ListNode(-1), *tail = ret;
        ret->next = NULL;
        while (1) {
            curr = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && (curr == -1 || lists[curr]->val > lists[i]->val)) {
                    curr = i;
                }
            }
            if (curr == -1) {
                return ret->next;
            }
            ListNode* p = lists[curr];
            lists[curr] = p->next;
            p->next = tail->next;
            tail->next = p;
            tail = tail->next;
        }
    }
};