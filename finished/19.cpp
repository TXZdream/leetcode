#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(-1), *curr = pre;
        pre->next = head;
        for (int i = 0; i < n; i++) {
            curr = curr->next;
        }
        while(curr->next != NULL) {
            curr = curr->next;
            pre = pre->next;
        }
        if (pre->next == head) {
            return head->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};