//
// Created by segni on 14/01/2020.
//
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int size = 10000;
    ListNode* set[10000] = {NULL};

    MyHashSet() {

    }

    void add(int key) {
        ListNode *node = new ListNode(key), *temp = set[key % size];

        while (temp && temp->val != key)
            temp = temp->next;

        if (!temp) {
            node->next = set[key % size];
            set[key % size] = node;
        }

    }

    void remove(int key) {
        ListNode *node = set[key % size], *prev = node;
        if (node && node->val == key) {
            set[key % size] = node->next;
            return;
        }

        while (node && node->val != key) {
            prev = node;
            node = node->next;
        }

        if (node)
            prev->next = node->next;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        ListNode *node = set[key % size];

        while (node) {
            if (node->val == key)
                return true;
            node = node->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
