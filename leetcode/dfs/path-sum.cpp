//
// Created by segni on 17/01/2020.
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
    bool dfs(TreeNode *root, int sum, int num, TreeNode *prev) {
        if (!root)
            return sum == num && !(prev->left || prev->right);

        return dfs(root->left, sum + root->val, num, root) ||
               dfs(root->right, sum + root->val, num, root);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return root && dfs(root, 0, sum, root);
    }
};