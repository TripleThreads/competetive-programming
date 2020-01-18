//
// Created by segni on 18/01/2020.
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
    int dfs(TreeNode *cur, int depth) {
        if (!cur)
            return depth;
        return max(dfs(cur->left, depth + 1), dfs(cur->right, depth + 1));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left = dfs(root->left, 0);
        int right = dfs(root->right, 0);
        return left == right ? root : left > right ?
                                      lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};