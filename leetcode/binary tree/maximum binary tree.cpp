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
    TreeNode* construct(vector<int> nums) {

        if (nums.size() == 0) return nullptr;

        int max = 0, maxIndex = 0, i;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }

        TreeNode *root = new TreeNode(max);

        if (maxIndex > 0)
            root->left = construct(vector<int>(nums.begin(), nums.begin() + maxIndex));

        if (maxIndex < nums.size() - 1)
            root->right = construct(vector<int>(nums.begin() + 1 + maxIndex, nums.end()));

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
    }
};