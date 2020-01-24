//
// Created by segni on 24/01/2020.
//

// using stack
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stck;

        for (char c: S) {
            if (!stck.empty() && c == ')' && stck.top() == '(')
                stck.pop();
            else
                stck.push(c);
        }

        return stck.size();
    }
};

// without stack

class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0, closed = 0;
        for (char c : S) {
            if (c == '(')
                open++;
            else if (open > 0)
                open--;
            else
                closed++;
        }
        return closed + open;
    }
};