#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        if (root == NULL) {
            return ret;
        }
        ret = pathSum(root, sum, 0);
        for (int i = 0; i < ret.size(); i++) {
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    }

private:
    vector<vector<int>> pathSum(TreeNode* root, int sum, int currSum) {
        vector<vector<int> > ret;
        if (root == NULL) {
            return ret;
        }
        if (root->left == NULL && root->right == NULL) {
            if (currSum + root->val == sum) {
                vector<int> tmp;
                tmp.push_back(root->val);
                ret.push_back(tmp);
            }
            return ret;
        }
        vector<vector<int> > left = pathSum(root->left, sum, root->val + currSum);
        ret = pathSum(root->right, sum, root->val + currSum);
        for (int i = 0; i < left.size(); i++) {
            ret.push_back(left[i]);
        }
        for (int i = 0; i < ret.size(); i++) {
            ret[i].push_back(root->val);
        }
        return ret;
    }
};