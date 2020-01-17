//
// Created by segni on 17/01/2020.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxD = 0;
    int dfs(Node* root, int depth) {
        if (!root)
            return maxD;
        maxD = max(depth+1, maxD);
        for (Node *child : root->children)
            dfs(child, depth + 1);

        return maxD;
    }
    int maxDepth(Node* root) {
        return dfs(root, 0);
    }
};