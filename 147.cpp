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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* top = new ListNode(1);
        top->next = head;
        ListNode* curr = head;
        while (curr->next) {
            ListNode* ip = top;
            while (ip != curr) {
                if ((ip == top || curr->next->val >= ip->val) && curr->next->val <= ip->next->val) {
                    ListNode* tmp = curr->next;
                    curr->next = tmp->next;
                    tmp->next = ip->next;
                    ip->next = tmp;
                    break;
                }
                ip = ip->next;
            }
            if (ip == curr) {
                curr = curr->next;
            }
        }
        return top->next;
    }
};