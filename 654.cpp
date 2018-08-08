#include <iostream>
#include <vector>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (maxIndex == -1 || nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        if (maxIndex == -1) {
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        if (maxIndex >= 1) {
            vector<int> leftV(nums.begin(), nums.begin() + maxIndex);
            root->left = constructMaximumBinaryTree(leftV);
        }
        if (maxIndex <= nums.size() - 1) {
            vector<int> right(nums.begin() + maxIndex + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};