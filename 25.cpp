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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode* front = new ListNode(-1), *from = head, *to = head;
        front->next = NULL;
        bool isK = true;
        ListNode* inComplete = NULL;
        do {
            for (int i = 0; i < k - 1; i++) {
                if (to->next == NULL) {
                    if (i <= k - 2) {
                        isK = false;
                    }
                    break;
                }
                to = to->next;
            }
            if (isK) {
                ListNode* tmp = to->next;
                to->next = front->next;
                front->next = from;
                from = tmp;
                to = tmp;
            } else {
                inComplete = from;
                break;
            }
        } while (to != NULL);
        head = front->next;
        front->next = NULL;
        while (head != NULL) {
            from = head->next;
            head->next = front->next;
            front->next = head;
            head = from;
        }
        if (!isK) {
            from = front;
            while (from->next) {
                from = from->next;
            }
            from->next = inComplete;
        }
        return front->next;
    }
};