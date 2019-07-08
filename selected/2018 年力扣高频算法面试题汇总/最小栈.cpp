#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new Node();
        head->next = NULL;
    }
    
    void push(int x) {
        bool isFirst = false;
        if (head ->next == NULL) {
            isFirst = true;
        }
        Node* tmp = new Node;
        tmp->val = x;
        if (isFirst || x < min) {
            min = x;
        }
        tmp->next = head->next;
        head->next = tmp;
    }
    
    void pop() {
        if (head ->next == NULL) {
            return;
        }
        int val = top();
        Node* tmp = head->next;
        head->next = tmp->next;
        delete tmp;
        if (val != min) {
            return;
        }
        Node* curr = head;
        bool isSet = false;
        int currMin;
        while (curr->next) {
            if (!isSet || curr->next->val < currMin) {
                currMin = curr->next->val;
                isSet = true;
            }
            curr = curr->next;
        }
        min = currMin;
    }
    
    int top() {
        return head->next->val;
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    Node* head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */