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
    int size = 0;
    int depth(TreeNode* root, int dp) {
        return !root ? dp : max(depth(root->left, dp + 1), depth(root->right, dp + 1));
    }
    void dfs(TreeNode *root, int dp, vector<vector<int>> &result) {
        if (!root) return;
        result[size - dp].push_back(root->val);
        dfs(root->left, dp + 1, result);
        dfs(root->right, dp + 1, result);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        size = depth(root, 0) - 1;
        vector<vector<int>> result(size + 1);
        dfs(root, 0, result);
        return result;
    }
};