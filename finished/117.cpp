#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<int> level;
        queue<Node*> node;
        Node* lastNode = NULL;
        int lastLevel = 1;
        if (root == NULL) {
            return NULL;
        }
        level.push(1);
        node.push(root);
        while (!node.empty()) {
            int currLevel = level.front(); level.pop();
            Node* currNode = node.front(); node.pop();
            if (lastNode) {
                if (lastLevel != currLevel) {
                    lastNode->next = NULL;
                } else {
                    lastNode->next = currNode;
                }
            }
            lastNode = currNode;
            lastLevel = currLevel;
            if (lastNode->left) {
                node.push(lastNode->left);
                level.push(lastLevel+1);
            }
            if (lastNode->right) {
                node.push(lastNode->right);
                level.push(lastLevel+1);
            }
        }
        lastNode->next = NULL;
        return root;
    }
};