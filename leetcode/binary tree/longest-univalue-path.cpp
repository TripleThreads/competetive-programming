//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int _max = 0;
    int longest(TreeNode* root) {

        if (!root) return 0;

        int left = longest(root->left);
        int right = longest(root->right);

        if (root->left && root->left->val == root->val)
            left++;
        else
            left = 0;

        if (root->right && root->right->val == root->val)
            right++;
        else
            right = 0;

        _max = max(_max, right + left);

        return max(right, left);

    }
    int longestUnivaluePath(TreeNode* root) {
        longest(root);
        return _max;
    }
};