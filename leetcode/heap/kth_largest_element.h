//
// Created by segni on 26/12/2019.
//
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

        if (nums.size() > k) {
            sort(nums.begin(), nums.end());

            for (int i = nums.size() - k; i < nums.size(); i++)
                array.push_back(nums[i]);
        }
        else
            this->array = nums;

        // last non leaf node;
        int n = (nums.size() / 2) - 1, size = nums.size();

        for (int i = n; i >= 0; i--) {
            heapify_down(i);
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