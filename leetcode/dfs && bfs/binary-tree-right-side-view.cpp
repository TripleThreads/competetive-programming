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
    vector<int> result;
    void dfs(TreeNode *root, int total) {

        if (!root)
            return;

        if (result.size() == total)
            result.push_back(root->val);

        dfs(root->right, total + 1);
        dfs(root->left, total + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};