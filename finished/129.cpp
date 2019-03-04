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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> ret = sum(root, 0);
        int sum = 0;
        for (int i = 0; i < ret.size(); i++) {
            sum += ret[i];
        }
        return sum;
    }
private:
    vector<int> sum(TreeNode* root, int up) {
        vector<int> ret;
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(up * 10 + root->val);
            return ret;
        }
        vector<int> left;
        if (root->left != NULL) {
            left = sum(root->left, up * 10 + root->val);
        }
        if (root->right != NULL) {
            ret = sum(root->right, up * 10 + root->val);
        }
        for (int i = 0; i < left.size(); i++) {
            ret.push_back(left[i]);
        }
        return ret;
    }
};