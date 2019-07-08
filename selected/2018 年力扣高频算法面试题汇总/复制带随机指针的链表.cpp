#include<iostream>
#include<vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head, *prev = NULL, *newHead = NULL;
        while (curr != NULL) {
            Node* tmp = new Node(curr->val, curr->next, NULL);
            if (newHead == NULL) {
                newHead = tmp;
            }
            curr->next = tmp;
            curr = tmp->next;
        }
        curr = head;
        while (curr != NULL) {
            cout << curr->val << endl;
            if (curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL) {
            Node* tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = tmp->next->next;
            curr = curr->next;
        }
        return newHead;
    }
};