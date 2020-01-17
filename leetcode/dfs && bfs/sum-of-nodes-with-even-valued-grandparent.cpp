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
    int sum = 0;

    void dfs(TreeNode *current, TreeNode *parent, TreeNode* grandParent) {
        if (!current)
            return;

        if (grandParent && grandParent->val % 2 == 0)
            sum += current->val;

        dfs(current->left, current, parent);
        dfs(current->right, current, parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, nullptr, nullptr);
        return sum;
    }
};