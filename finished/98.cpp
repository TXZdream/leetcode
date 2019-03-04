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
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        inOrder(root, result);
        for (int i = 1; i < result.size(); i++) {
            if (result[i] <= result[i-1]) {
                return false;
            }
        }
        return true;
    }
private:
    void inOrder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            inOrder(root->left, result);
        }
        result.push_back(root->val);
        if (root->right) {
            inOrder(root->right, result);
        }
    }
};