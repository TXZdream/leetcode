#include<iostream>
#include<vector>
#include<stack>
#include<list>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        list<TreeNode*> node;
        list<int> layer;
        stack<vector<int> > tmp;
        if (root == NULL) {
            return ret;
        }
        node.push_back(root);
        layer.push_back(0);
        while(!node.empty()) {
            TreeNode* top = node.front();
            node.pop_front();
            int topLayer = layer.front();
            layer.pop_front();
            if (topLayer == tmp.size()) {
                vector<int> cur;
                tmp.push(cur);
            }
            tmp.top().push_back(top->val);
            if (top->left != NULL) {
                node.push_back(top->left);
                layer.push_back(topLayer + 1);
            }
            if (top->right != NULL) {
                node.push_back(top->right);
                layer.push_back(topLayer + 1);
            }
        }
        while (!tmp.empty()) {
            ret.push_back(tmp.top());
            tmp.pop();
        }
        return ret;
    }
};