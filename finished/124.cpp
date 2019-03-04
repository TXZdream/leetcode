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
    int maxPathSum(TreeNode* root) {
        int max = root->val;
        maxPathSum(root, &max);
        return max;
    }
private:
    int maxPathSum(TreeNode* root, int* max) {
        if (root == NULL) {
            return 0;
        }
        int left = 0, right = 0;
        if (root->left) {
            left = maxPathSum(root->left, max);
        }
        if (root->right) {
            right = maxPathSum(root->right, max);
        }
        int bigger = left;
        if (right > bigger) {
            bigger = right;
        }
        bigger += root->val;
        if (bigger > *max) {
            *max = bigger;
        }
        if (left + right + root->val > *max) {
            *max = left + right + root->val;
        }
        return bigger>0?bigger:0;
    }
};