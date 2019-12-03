//
// Created by segni on 03/12/2019.
//

void postfix_calculator() {
    class Stack stack;
    string input;
    cout << "Enter prefix expression " << endl;
    getline(cin, input);

    vector<string> results = split(input);
    int result_size = results.size();
    unordered_set<char> operations = {'+', '-', '/', '*',};

    for (int i = 0; i < result_size; i++) {
        char op = ' ';
        if (results[i].length() == 1)
            op = results[i][0];

        if (operations.find(op) == operations.end()) {
            stack.push(stoi(results[i]));
        } else {
            int x = stack.pop();
            int y = stack.pop();
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
                    cout << "mul res " << result << endl;
                    break;

                case '/':
                    result = y / x;
                    cout << result << endl;
                    break;
            }
            stack.push(result);
        }
    }
    cout << "result " << stack.pop() << endl;
}