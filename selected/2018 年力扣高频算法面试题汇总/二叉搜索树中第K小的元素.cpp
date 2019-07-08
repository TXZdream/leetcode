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
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        return kthSmallest(root, k, ret);
    }
private:
    int kthSmallest(TreeNode* root, int k, int& order) {
        int ret;
        if (root->left != NULL) {
            ret = kthSmallest(root->left, k, order);
        }
        if (order == k) {
            return ret;
        }
        order++;
        if (order == k) {
            return root->val;
        }
        if (root->right != NULL) {
            return kthSmallest(root->right, k, order);
        }
        return -1;
    }
};