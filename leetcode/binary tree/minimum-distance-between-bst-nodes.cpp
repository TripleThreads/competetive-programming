//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int minDiffInBST(TreeNode* root) {

        int min = INT_MAX, diff;

        stack<TreeNode*> nodes;
        vector<int> result;

        while(root || !nodes.empty()) {

            if (root) {
                nodes.push(root);
                root = root->left;
            }
            else if (!nodes.empty()) {
                root = nodes.top();
                nodes.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }

        for (int i = 0; i < result.size() - 1; i++) {
            if (abs(result[i] - result[i + 1]) < min) {
                min = abs(result[i] - result[i + 1]);
            }
        }
        return min;
    }
};