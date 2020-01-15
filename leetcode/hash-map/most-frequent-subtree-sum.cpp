//
// Created by segni on 15/01/2020.
//

class Solution {
public:
    vector<int> nums;
    map<int, int> mp;

    int postOrder(TreeNode *root) {
        if (!root)
            return 0;
        int val = root->val + postOrder(root->left) + postOrder(root->right);
        mp[val]++;
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        postOrder(root);

        int rep = 1;
        for (const auto &[key, value] : mp)
            rep = max(rep, value);

        for (const auto &[key, value] : mp)
            if (value == rep)
                result.push_back(key);

        return result;
    }
};