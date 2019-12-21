//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode *root = new TreeNode(preorder[0]), *iter = root;

        stack<TreeNode*> items;

        items.push(root);

        int i = 1;

        while (!items.empty() && i < preorder.size()) {

            while (!items.empty() && items.top()->val < preorder[i])  {
                iter = items.top();
                items.pop();
            }
            if (iter->val > preorder[i]) {
                iter->left = new TreeNode(preorder[i++]);
                items.push(iter->left);
                iter = iter->left;
            }
            else {
                iter->right = new TreeNode(preorder[i++]);
                items.push(iter->right);
                iter = iter->right;
            }
        }
        return root;
    }
};