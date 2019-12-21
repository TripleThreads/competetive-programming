//
// Created by segni on 21/12/2019.
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

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (!root) return 0;

        if (root->val >= L && root->val <= R) {
            sum += root->val;
        }

        else if (root->val <= L)
            sum += rangeSumBST(root->right, L, R);

        else
            sum += rangeSumBST(root->left, L, R);

        return sum;
    }
};