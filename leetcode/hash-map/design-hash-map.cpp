//
// Created by segni on 14/01/2020.
//

struct LinkedList {
    int key;
    int value;
    LinkedList *next;
    LinkedList(int k, int v) : key(k), value(v), next(NULL) {
    }

};

class MyHashMap {
public:
    int size = 10000;
    LinkedList* n[10000] = {NULL};

    /** Initialize your data structure here. */
    MyHashMap() {
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        LinkedList *node = new LinkedList(key, value);

        LinkedList *temp = n[key % size];
        while (temp && temp->key != key)
            temp = temp->next;

        if (temp)
            temp->value = value;

        else{
            node->next = n[key % size];
            n[key % size] = node;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        LinkedList* node = n[key % size];
        while (node && node->key != key)
            node = node->next;

        if (node)
            return node->value;
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {

        LinkedList* node = n[key % size], *prev = node;

        if (node && node->key == key)
            n[key % size] = node->next;

        while (node && node->key != key) {
            prev = node;
            node = node->next;
        }
        if (node)
            prev->next = node->next;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */