//
// Created by segni on 30/11/2020.
//

class Solution {
public:
    int dfs(TreeNode *root, vector<TreeNode*> &res, unordered_set<int> &del) {
        if (!root) return -10000;
        bool found = false;
        if ((found = del.count(root->val))) {
            if (root->left && !del.count(root->left->val))
                res.push_back(root->left);
            if (root->right && !del.count(root->right->val))
                res.push_back(root->right);
            del.erase(root->val);
        }
        int lf = dfs(root->left, res, del);
        int rt = dfs(root->right, res, del);

        root->left = lf == 1 ? nullptr: root->left; // if the child is deleted parent have to point to NULL.
        root->right = rt == 1 ? nullptr: root->right;

        return found ? 1 : 1 + min(lf, rt);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> del(begin(to_delete), end(to_delete));
        if (!del.count(root->val)) res.push_back(root);
        dfs(root, res, del);

        return res;
    }
};