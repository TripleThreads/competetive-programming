//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    vector<int> iter(TreeNode* root, int ix, vector<int> &max) {

        if (root && !root->left && !root->right) return {root->val, ix};

        vector<int> left, right;

        if (root) {

            right = iter(root->right, ix + 1, max);


            left = iter(root->left, ix + 1, max);

            if (max[1] <= left[1])
                max = left;
        }
        return max;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> max = {root->val, 0};
        return iter(root, 0, max)[0];
    }
};