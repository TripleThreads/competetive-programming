//
// Created by segni on 07/02/2020.
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
    vector<int> inOrderTraversal(TreeNode *root) {
        vector<int> nums;
        TreeNode *current = root, *pre = nullptr;
        if (!root) return {};

        while (current) {
            if (!current->left) {
                nums.push_back(current->val);
                current = current->right;
            }
            else  {
                pre = current->left;
                while (pre->right && pre->right != current)
                    pre = pre->right;

                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                }

                else {
                    pre->right = nullptr;
                    nums.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return nums;

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums, r1, r2;
        // inorder traversal
        r1 = inOrderTraversal(root1);
        r2 = inOrderTraversal(root2);

        int i = 0, j = 0;
        // merge
        while (i < r1.size() && j < r2.size()) {
            if (r1[i] < r2[j])
                nums.push_back(r1[i++]);

            else
                nums.push_back(r2[j++]);
        }
        while (i < r1.size())
            nums.push_back(r1[i++]);

        while (j < r2.size())
            nums.push_back(r2[j++]);
        return nums;
    }
};