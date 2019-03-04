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
    void reorderList(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr!= NULL) {
            length++;
            curr = curr->next;
        }
        if (length <= 2) {
            return;
        }
        curr = head;
        for (int i = 0; i < length / 2 + length % 2 - 1; i++) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = NULL;
        curr = tmp;

        ListNode* back = NULL;
        while (curr != NULL) {
            tmp = curr;
            curr = curr->next;
            tmp->next = back;
            back = tmp;
        }

        ListNode* front = head;
        curr = NULL; head = NULL;
        while (front || back) {
            if (front) {
                cout << front->val << "v";
                if (head == NULL) {
                    head = front;
                    curr = front;
                } else {
                    curr->next = front;
                    curr = front;
                }
                front = front->next;
            }
            if (back) {
                cout << back->val << "v";
                curr->next = back;
                curr = back;
                back = back->next;
            }
        }
        curr->next = NULL;
    }
};