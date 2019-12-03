//
// Created by segni on 04/12/2019.
//

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node *node = nullptr;
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *head = node;
        int ix = 0;
        while (ix < index) {
            head = head->next;
            ix++;
        }

        if (!head) return -1;
        return head->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *temp = new Node(val);
        temp->next = node;
        node = temp;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp = new Node(val);

        if (!node) {
            node = temp;
            return;
        }

        Node *head = node;

        while (head->next) {
            head = head->next;
        }

        head->next = temp;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        Node *temp = new Node(val);

        if (index == 0) {
            temp->next = node;
            node = temp;
            return;
        }

        Node *head = node;
        int ix = 0;

        while (ix < index - 1 && head->next) {
            head = head->next;
            ix++;
        }
        while (ix < index - 1 && !head->next) {
            head = new Node(-1);
            head = head->next;
            ix++;
        }

        Node *prev = head;
        if (head) {
            temp->next = head->next;
            prev->next = temp;
        }
        else {
            head = temp;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if (index == 0) {
            node = node->next;
            return;
        }
        Node *head = node;
        int ix = 0;

        while (ix < index - 1 && head->next) {
            head = head->next;
            ix++;
        }
        if (head->next)
            head->next = head->next->next;
        else {
            head->next = nullptr;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */