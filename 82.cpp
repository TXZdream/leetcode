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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* front = new ListNode(-1), *prev = front;
        front->next = head;
        bool isSet = false;
        int rec = -1;
        while (prev->next != NULL) {
            if (isSet && rec == prev->next->val) {
                prev->next = prev->next->next;
                continue;
            }
            if (prev->next->next && prev->next->val == prev->next->next->val) {
                prev->next = prev->next->next;
                isSet = true;
                rec = prev->next->val;
                continue;
            }
            prev = prev->next;
        }
        return front->next;
    }
};