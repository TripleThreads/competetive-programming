//
// Created by segni on 11/12/2019.
//
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        if (!root) return {};

        stack<TreeNode *> lefties;
        vector<int> result;

        result.push_back(root->val);
        lefties.push(root->left);

        root = root->right;

        while (!lefties.empty() || root) {

            if (!root) {
                root = lefties.top();
                lefties.pop();
            }
            if (!root) continue;

            if (root->left)
                lefties.push(root->left);

            result.push_back(root->val);
            root = root->right;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};