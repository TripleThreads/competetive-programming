//
// Created by segni on 02/02/2020.
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
    vector<vector<int>> result;

    void dfs(TreeNode *root, int dp) { // returns depth of my tree
        if (!root) return;
        if (result.size() == dp) // if my result is empty or didnt reach this depth before
            result.push_back({root->val});
        else
            result[dp].push_back(root->val);

        dfs(root->left, dp + 1);
        dfs(root->right, dp + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        dfs(root, 0);
        return result;
    }
};