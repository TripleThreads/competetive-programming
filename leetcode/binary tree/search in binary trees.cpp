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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;

        if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};