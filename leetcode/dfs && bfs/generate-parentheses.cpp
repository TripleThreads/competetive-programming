//
// Created by segni on 11/03/2020.
//

struct Paren {
    int left;
    int right;
    string par;
    Paren(int l, int r, string s) : left(l), right(r), par(s) {}
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<Paren> que;
        que.push(Paren(1, 0, "("));
        vector<string> res;
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (cur.left < cur.right || cur.left > n || cur.right > n)
                continue;
            if (cur.left == n && cur.right == n) {
                res.push_back(cur.par);
            }

            que.push(Paren(cur.left + 1, cur.right, cur.par + "("));
            if (cur.left > cur.right)
                que.push(Paren(cur.left, cur.right + 1, cur.par + ")"));
        }
        return res;
    }
};