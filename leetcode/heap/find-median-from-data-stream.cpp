//
// Created by segni on 15/03/2020.
//

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = 0;
    MedianFinder() {

    }

    void addNum(int num) {

        if (++n / 2 > maxHeap.size()) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (!maxHeap.empty() && num < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.push(num);
            maxHeap.pop();
        }
        else {
            minHeap.push(num);
        }
    }

    double findMedian() {
        return n % 2 ? minHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */