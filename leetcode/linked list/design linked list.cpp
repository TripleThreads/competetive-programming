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
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

        Node *node = head;
        int ix = 0;
        while (ix < index && node) {
            node = node->next;
            ix++;
        }
        if (!node) return -1;
        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val);
        node->next = head;
        head = node;
        if (!head->next)
            tail = node;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
            return;
        }
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node *temp = new Node(val);
        Node *node = head;

        int ix = 0;

        if (index < size) {
            while (ix < index - 1 && node->next) {
                node = node->next;
                ix++;
            }
            temp->next = node->next;
            node->next = temp;
        } else {
            node = tail;
            node->next = temp;
            tail = temp;
        }
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if (index == 0) {
            head = head->next;
            return;
        }
        Node *node = head;
        int ix = 0;

        while (ix < index - 1 && node->next) {
            node = node->next;
            ix++;
        }

        if (node->next) {
            node->next = node->next->next;
            size--;
        }
        if (!node->next) {
            tail = node;
        }

    }
};

void linkedListDesign() {
    class MyLinkedList myLinkedList;
    myLinkedList.addAtHead(86);
    myLinkedList.addAtIndex(1, 54);
    myLinkedList.addAtIndex(1, 14);
    myLinkedList.addAtHead(83);
    cout << myLinkedList.get(4) << endl;
    myLinkedList.deleteAtIndex(4);
    myLinkedList.addAtIndex(3, 18);
    myLinkedList.addAtHead(46);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtHead(76);

    cout << myLinkedList.get(5) << endl;
}