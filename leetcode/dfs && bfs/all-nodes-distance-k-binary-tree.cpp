//
// Created by segni on 29/11/2020.
//

class Solution {
public:
    const int NOT_FOUND = 10000;
    // returns distance
    int find(TreeNode *root, TreeNode* target, int depth, int cur, int k, vector<int> &res) {
        if (!root) return NOT_FOUND;
        if (cur - depth == k)
            res.push_back(root->val);

        if (root == target) {
            find(root->left, target, 0, 1, k, res);
            find(root->right, target, 0, 1, k, res);
            if (k == 0) res.push_back(root->val);
            return 1;
        }
        int lf = find(root->left, target, depth, cur + 1, k, res);
        int rt = find(root->right, target, depth, cur + 1, k, res);

        if (lf == k || rt == k)
            res.push_back(root->val);

        else if (lf < k)
            find(root->right, target, 0, 1, k - lf, res);

        else if (rt < k)
            find(root->left, target, 0, 1,  k - rt, res);

        return 1 + (lf  <= 500 ? lf : rt);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        find(root, target, NOT_FOUND, 0, K, res);
        return res;
    }
};