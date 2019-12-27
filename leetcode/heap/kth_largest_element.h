class KthLargest {
public:
    int size, maxSize;
    vector<int> array;

    void heapify_down(int parent) {
        int smallest = parent;
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left < size && array[left] < array[smallest])
            smallest = left;

        if (right < size && array[right] < array[smallest])
            smallest = right;

        if (smallest != parent) {
            swap(array[parent], array[smallest]);
            heapify_down(smallest);
        }
    }

    KthLargest(int k, vector<int>& nums) {
        this->maxSize = k;

        this->array = nums;
        this->size = array.size();

        // last non leaf node;
        int n = (size / 2) - 1;

        for (int i = n; i >= 0; i--) {
            heapify_down(i);
        }
        while (size > k) { // delete until it is equal to k
            swap(array[0], array[size - 1]);
            size--;
            heapify_down(0);
            array.pop_back();
        }
    }

    int add(int val) {

        size = array.size();

        if (size >= maxSize && val < array[0]) return array[0];

        else if (size >= maxSize)
            array[0] = val;
        else {
            array.push_back(val);
            size++;
        }

        heapify_down(0);
        return array[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */