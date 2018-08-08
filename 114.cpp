#include<iostream>
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
    void flatten(TreeNode* root) {
        flat(root);
    }
private:
    TreeNode* flat(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        if (root->left == NULL) {
            return flat(root->right);
        }
        TreeNode* tail = flat(root->left);
        if (root->right != NULL) {
            tail->right = root->right;
            tail = flat(tail->right);
        }
        root->right = root->left;
        root->left = NULL;
        return tail;
    }
};