//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        vector<int> stack;

        int result_size = tokens.size();

        unordered_set<char> operations = {'+', '-', '/', '*',};

        for (int i = 0; i < result_size; i++) {

            char op = ' ';

            if (tokens[i].length() == 1)
                op = tokens[i][0];

            if (operations.find(op) == operations.end()) {

                stack.push_back(stoi(tokens[i]));

            } else {
                int x = stack[stack.size() - 1];

                stack.pop_back();

                int y = stack[stack.size() - 1];

                stack.pop_back();

                int result = 0;

                switch (op) {
                    case '+':
                        result = x + y;
                        break;

                    case '-':
                        result = y - x;
                        break;

                    case '*':
                        result = x * y;
                        break;

                    case '/':
                        result = y / x;
                        break;
                }
                stack.push_back(result);
            }
        }
        return stack[0];

    }
};