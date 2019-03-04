#include<iostream>
#include<vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return root;
        }
        int pos = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                pos = i;
                break;
            }
        }
        if (pos > 0) {
            vector<int> left(inorder.begin(), inorder.begin() + pos);
            vector<int> pre(preorder.begin() + 1, preorder.begin() + pos + 1);
            root->left = buildTree(pre, left);
        }
        if (pos < inorder.size() - 1) {
            vector<int> right(inorder.begin() + pos + 1, inorder.end());
            vector<int> pre(preorder.begin() + pos + 1, preorder.end());
            root->right = buildTree(pre, right);
        }
        return root;
    }
};