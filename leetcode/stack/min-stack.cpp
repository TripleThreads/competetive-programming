//
// Created by segni on 21/12/2019.
//

class MinStack {
public:
    /** Initialize your data structure here. */
    int index = -1;

    int min = INT_MAX;

    vector<vector<int>> _data;
    MinStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {

        if (min > x) {
            min = x;
        }
        this->_data.push_back({x, min});
        this->index++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto x = this->_data[this->index--];
        _data.pop_back();
        return x[0];
    }

    /** Get the top element. */
    int top() {
        return this->_data[this->index][0];
    }

    int getMin() {

        return this->_data[this->index][1];
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */