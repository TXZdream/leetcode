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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> ret;
            return ret;
        }
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int begin, int end) {
        vector<TreeNode*> ret;
        if (begin > end) {
            ret.push_back(NULL);
            return ret;
        }
        if (begin == end) {
            TreeNode* root = new TreeNode(begin);
            ret.push_back(root);
            return ret;
        }
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> left = generateTrees(begin, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* current = new TreeNode(i);
                    current->left = left[j];
                    current->right = right[k];
                    ret.push_back(current);
                }
            }
        }
        return ret;
    }
};