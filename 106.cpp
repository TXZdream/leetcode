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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(*(postorder.end() - 1));
        if (postorder.size() == 1) {
            return root;
        }
        int pos = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (root->val == inorder[i]) {
                pos = i;
                break;
            }
        }
        if (pos > 0) {
            vector<int> left(inorder.begin(), inorder.begin() + pos);
            vector<int> post(postorder.begin(), postorder.begin() + pos);
            root->left = buildTree(left, post);
        }
        if (pos < inorder.size() - 1) {
            vector<int> right(inorder.begin() + pos + 1, inorder.end());
            vector<int> post(postorder.begin() + pos, postorder.end() - 1);
            root->right = buildTree(right, post);
        }
        return root;
    }
};