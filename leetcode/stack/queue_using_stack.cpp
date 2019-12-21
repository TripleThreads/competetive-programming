//
// Created by segni on 03/12/2019.
//

class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> stack;
    vector<int> stack_backup;
    int index_data = -1;
    int index_backup = -1;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
        index_data++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int value = 0;
        if (index_backup >= 0) {
            value = stack_backup[index_backup--];
            stack_backup.pop_back();
            return value;
        }
        while (index_data >= 0) {
            value = stack[index_data--];
            stack.pop_back();
            stack_backup.push_back(value);
            index_backup++;
        }
        stack_backup.pop_back();
        index_backup--;
        return value;
    }

    /** Get the front element. */
    int peek() {
        int value = 0;
        if (index_backup >= 0) {
            value = stack_backup[index_backup];
            return value;
        }
        while (index_data >= 0) {
            value = stack[index_data--];
            stack.pop_back();
            stack_backup.push_back(value);
            index_backup++;
        }
        return value;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return index_backup == -1 && index_data == -1;
    }
};


void queue_using_stack() {
    class MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;
    cout << queue.pop() << endl;
    cout << queue.peek() << endl;
    cout << queue.pop() << endl;
    cout << queue.empty() << endl;
}