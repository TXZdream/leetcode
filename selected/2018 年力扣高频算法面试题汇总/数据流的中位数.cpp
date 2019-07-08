#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
        head = new Node;
        head->next = NULL;
    }
    
    void addNum(int num) {
        size++;
        Node* tmp = new Node;
        tmp->val = num;
        Node* curr = head;
        while (curr) {
            if ((curr == head || curr->val <= num) && (curr->next == NULL || curr->next->val >= num)) {
                tmp->next = curr->next;
                curr->next = tmp;
                return;
            }
            curr = curr->next;
        }
    }
    
    double findMedian() {
        Node* curr = head;
        for (int i = 0; i < (size + 1) / 2; i++) {
            curr = curr->next;
        }
        double val = curr->val;
        if (size % 2 == 0) {
            val = (val + curr->next->val) / 2;
        }
        return val;
    }
private:
    int size;
    Node* head;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */