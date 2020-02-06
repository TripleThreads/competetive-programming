//
// Created by segni on 06/02/2020.
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
    long long int sum = 0, MAX = 0;
    void total(TreeNode *root){
        if (!root) return;
        sum += root->val;
        total(root->left);
        total(root->right);
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;
        long int left = dfs(root->left);
        long int right = dfs(root->right);
        MAX = max({MAX, (sum - left) * left, (sum - right) * right});
        return root->val + left + right;
    }
    int maxProduct(TreeNode* root) {
        int MOD=1e9+7;
        total(root);
        dfs(root);
        return MAX % MOD;
    }
};