//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (!root) return new TreeNode(val);

        if (!root->left && root->val > val)
            root->left = new TreeNode(val);

        else if (!root->right && root->val < val)
            root->right = new TreeNode(val);

        else if (root->val < val)
            insertIntoBST(root->right, val);

        else
            insertIntoBST(root->left, val);

        return root;

    }
};