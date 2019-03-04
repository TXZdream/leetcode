#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<int> level;
        queue<TreeNode*> node;
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        node.push(root);
        level.push(1);
        int lastLevel = 1;
        vector<int> tmp;
        while (!node.empty()) {
            int currLevel = level.front(); level.pop();
            TreeNode* currNode = node.front(); node.pop();
            if (lastLevel != currLevel) {
                result.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(currNode->val);
            lastLevel = currLevel;
            if (currNode->left) {
                node.push(currNode->left);
                level.push(currLevel+1);
            }
            if (currNode->right) {
                node.push(currNode->right);
                level.push(currLevel+1);
            }
        }
        result.push_back(tmp);
        return result;
    }
};