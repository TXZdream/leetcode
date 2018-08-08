#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        list<int> layer;
        list<TreeNode*> node;
        stack<int> tmp;
        vector<vector<int> > ret;
        if (root == NULL) {
            return ret;
        }
        layer.push_back(0);
        node.push_back(root);

        while(1) {
            if (node.empty()) {
                while (!tmp.empty()) {
                    int top = tmp.top();
                    tmp.pop();
                    (ret.end() - 1)->push_back(top);
                }
                return ret;
            }
            int currLayer = layer.front();
            layer.pop_front();
            TreeNode* currNode = node.front();
            node.pop_front();
            if (ret.size() == currLayer) {
                if (currLayer % 2 == 0) {
                    while (!tmp.empty()) {
                        int top = tmp.top();
                        tmp.pop();
                        (ret.end() - 1)->push_back(top);
                    }
                }
                vector<int> newLayer;
                ret.push_back(newLayer);
            }
            if (currLayer % 2 == 0) {
                (ret.end() - 1)->push_back(currNode->val);
            } else {
                tmp.push(currNode->val);
            }
            if (currNode->left != NULL) {
                layer.push_back(currLayer+1);
                node.push_back(currNode->left);
            }
            if (currNode->right != NULL) {
                layer.push_back(currLayer+1);
                node.push_back(currNode->right);
            }
        }
    }
};