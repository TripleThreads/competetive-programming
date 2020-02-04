//
// Created by segni on 04/02/2020.
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
    vector<TreeNode* > vec;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        vec.push_back(root);
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root);
        TreeNode * node = new TreeNode(vec[0]->val);
        root = node;
        for (int i = 1; i < vec.size(); i++) {
            node->right = new TreeNode(vec[i]->val);
            node = node->right;
        }
        return root;
    }
};