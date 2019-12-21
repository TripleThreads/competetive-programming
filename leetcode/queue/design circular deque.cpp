//
// Created by segni on 21/12/2019.
//

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {
    }
};
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    Node *head = NULL, *tail = NULL;
    int maxSize = 0, size = 0;

    MyCircularDeque(int k) {
        maxSize = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (maxSize == size)
            return false;

        Node *node = new Node(value);

        if (!head) {
            head = node;
            tail = head;
        }
        else {
            node->next = head;
            head = node;
        }
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {

        if (maxSize == size) return false;

        if (!head)
            return insertFront(value);

        tail->next = new Node(value);
        tail = tail->next;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {

        if (!head) return false;

        head = head->next;

        if (size == 1)
            tail = head;

        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {

        if (!head) return false;
        if (!head->next) {
            head = nullptr;
            tail = head;
            size--;
            return true;
        }
        Node *temp = head, *prev = temp;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tail = prev;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (head) {
            return head->val;
        }
        return -1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (tail)
            return tail->val;

        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */