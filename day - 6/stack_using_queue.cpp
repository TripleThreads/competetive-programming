//
// Created by segni on 03/12/2019.
//

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> _queue;

    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        this->_queue.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        swapQueue();
        int val = _queue.front();
        _queue.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        swapQueue();
        int val = _queue.front();
        _queue.pop();
        _queue.push(val);
        return val;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _queue.empty();
    }

    void swapQueue() {
        queue<int> b = _queue;
        for (int i = 0; i < _queue.size() - 1; i++) {
            _queue.push(_queue.front());
            _queue.pop();
        }
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

void stack_using_queue() {
    class MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;

}