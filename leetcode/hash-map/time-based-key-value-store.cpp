//
// Created by segni on 16/01/2020.
//

struct LinkedList{
    int timestamp;
    string value;
    LinkedList *next;
    LinkedList(int t, string v): value(v), timestamp(t), next(NULL){}
};
class TimeMap {
public:
    unordered_map<string, LinkedList*> umap;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        LinkedList *node = new LinkedList(timestamp, value);
        node->next = umap[key];
        umap[key] = node;
    }

    string get(string key, int timestamp) {
        LinkedList *iter = umap[key];
        while (iter) {
            if (iter->timestamp <= timestamp)
                return iter->value;
            iter = iter->next;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */