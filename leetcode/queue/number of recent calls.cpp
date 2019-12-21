//
// Created by segni on 21/12/2019.
//
class RecentCounter {
public:

    queue<int> que;
    int size = 0;

    RecentCounter() {

    }

    int ping(int t) {
        que.push(t);
        size++;
        while (!que.empty() && que.front() < t - 3000) {
            que.pop();
            size--;
        }
        return size;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
