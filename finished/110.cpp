#include<iostream>
#include<math.h>
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return cnt(root) > -1;
    }

private:
    int cnt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = 0, right = 0;
        if (root->left != NULL) {
            left = cnt(root->left);
            if (left == -1) {
                return -1;
            }
        }
        if (root->right != NULL) {
            right = cnt(root->right);
            if (right == -1) {
                return -1;
            }
        }
        if (abs(left - right) > 1) {
            return -1;
        }
        if (left > right) {
            return left + 1;
        }
        return right + 1;
    }
};