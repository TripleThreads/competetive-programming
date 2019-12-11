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

        stack<TreeNode *> nodes, lefties;

        nodes.push(root);
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

            nodes.push(root);
            root = root->right;
        }
        vector<int> result;

        while (!nodes.empty()) {
            result.push_back(nodes.top()->val);
            nodes.pop();
        }
        return result;
    }
};