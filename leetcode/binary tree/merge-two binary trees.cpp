//
// Created by segni on 21/12/2019.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* merge(TreeNode *n, TreeNode* t1, TreeNode* t2) {

        if (!t1 && !t2) return nullptr;

        if (t1 && t2) {
            n = new TreeNode(t1->val + t2->val);
            n->left = merge(n->left, t1->left, t2->left);
            n->right = merge(n->right, t1->right, t2->right);
        }

        else if (t1 && !t2) {
            n = new TreeNode(t1->val);
            n->left = merge(n->left, t1->left, t2);
            n->right = merge(n->right, t1->right, t2);
        }
        else if (!t1 && t2) {
            n = new TreeNode(t2->val);
            n->left = merge(n->left, t1, t2->left);
            n->right = merge(n->right, t1, t2->right);
        }
        return n;
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *n;
        return merge(n, t1, t2);
    }
};