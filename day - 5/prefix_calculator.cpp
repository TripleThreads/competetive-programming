//
// Created by segni on 28/11/2019.
//
#define MAX 1000

class Stack {
    int top;

public:
    int size;
    int mem[MAX];
public:
    Stack() {
        top = -1;
    }

    bool push(int num) {
        if (top > MAX) {
            cout << "Stack overflow" << endl;
            return false;
        }
        this->mem[++top] = num;
        cout << "Pushed to stack" << endl;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow " << endl;
            return 0;
        }
        return this->mem[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "stack is empty" << endl;
            return 0;
        }
        return this->mem[top];
    }

};

vector<string> split(string str, char delimiter) {

    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

void prefix_cal() {
    class Stack stack;
    string input;
    cout << "Enter prefix expression " << endl;
    cin >> input;

    std::vector<std::string> results = split(input, ' ');
    for (const string& result : results) {
        cout << result << endl;
    }
}
