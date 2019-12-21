//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int partition(vector<vector<int>> &array, int low, int high) {

        vector<int> pivot = array[high];

        int pivot_d = pow(pivot[0], 2) + pow(pivot[1], 2);

        int i = low;
        for (int j = low; j <= high - 1; j++) {

            vector<int> temp = array[j];

            int temp_d = pow(temp[0], 2) + pow(temp[1], 2);

            if (temp_d < pivot_d) {
                swap(array[j], array[i]);
                i++;
            }
        }
        swap(array[high], array[i]);
        return i;
    }
    void quick_sort(vector<vector<int>> &array, int low, int high) {

        if (low < high) {

            float pivot = partition(array, low, high);

            quick_sort(array, low, pivot - 1);
            quick_sort(array, pivot + 1, high);

        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        vector<vector<int>> result;

        quick_sort(points, 0, points.size() - 1);

        for (int i = 0; i < K; i++) {
            result.push_back(points[i]);
        }

        return result;
    }
};