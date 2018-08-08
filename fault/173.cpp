#include<iostream>
#include<vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        current = root;
        if (root == NULL) {
            return;
        }
        travel(root, NULL);
        while (current->left != NULL) {
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (current) {
            return true;
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        int ret = current->val;
        current = current->right;
        return ret;
    }

private:
    TreeNode* current;
    void travel(TreeNode* root, TreeNode* prev) {
        if (root->left != NULL) {
            travel(root->left, root);
        }
        if (root->right == NULL) {
            root->right = prev;
        } else {
            travel(root->right, prev);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */