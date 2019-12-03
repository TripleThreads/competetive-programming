//
// Created by segni on 28/11/2019.
//

class Stack {
private:
    vector<int> data;
public:

public:
    Stack() {
    }

    bool push(int num) {
        data.push_back(num);
        cout << "Pushed to stack" << endl;
        return true;
    }

    int pop() {
        int value = data[data.size() - 1];
        data.pop_back();
        return value;
    }

    int peek() {
        return data[data.size() - 1];
    }

    int empty() {
        return data.size() == 0;
    }

};

vector<string> split(const string& str) {

    string word;

    istringstream iss(str, istringstream::in);
    vector<string> word_list;

    while (iss >> word) {
        word_list.push_back(word);
    }
    return word_list;
}

void prefix_cal() {
    class Stack stack;
    string input;
    cout << "Enter prefix expression " << endl;
    getline(cin, input);

    vector<string> results = split(input);
    int result_size = results.size();

    unordered_set<char> operations = {'+', '-', '/', '*',};

    for (int i = result_size - 1; i >= 0; i--) {
        char operation = results[i][0];

        if (operations.find(operation) == operations.end()) {
            stack.push(stoi(results[i]));

        } else {
            int x = stack.pop();
            int y = stack.pop();
            int result = 0;

            switch (operation) {
                case '+':
                    result = x + y;
                    break;

                case '-':
                    result = x - y;
                    break;

                case '*':
                    result = x * y;
                    cout << "mul res " << result << endl;
                    break;

                case '/':
                    result = x / y;
                    break;
            }
            stack.push(result);
        }
    }
    cout << "result is " << stack.pop() << endl;
}
