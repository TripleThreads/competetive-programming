//
// Created by segni on 15/02/2020.
//
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(); // length of string s
        stack<pair<char, int>> stck;
        for (int i = 0; i < n; i++) {
            char c = s.at(i);
            if (!stck.empty() && c == ')' && stck.top().first == '(' )
                stck.pop();
            else
                stck.push({c, i});
        }
        int maxLen = 0, right = n;
        while (!stck.empty()) {
            auto [c, len] = stck.top();
            stck.pop();
            maxLen = max(maxLen, right - len);
            right = len;
        }
        return max(maxLen, right + 1) - 1;
    }
};