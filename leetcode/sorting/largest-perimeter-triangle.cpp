//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int partition(vector<int> &array, int low, int high) {

        int pivot = array[high];
        int i = low;

        for (int j = low; j <= high - 1; j++) {
            if (array[j] > pivot) {
                swap(array[j], array[i]);
                i++;
            }
        }
        swap(array[high], array[i]);

        return i;
    }

    void quick_sort(vector<int> &array, int low, int high) {
        if (low < high) {
            int pivot = partition(array, low, high);
            quick_sort(array, low, pivot - 1);
            quick_sort(array, pivot + 1, high);
        }
    }

    int largestPerimeter(vector<int>& A) {
        quick_sort(A, 0, A.size() - 1);

        int perimeter;


        float p = 0;

        float area = 0;

        int ix = 0;

        while (area == 0) {
            int z = 0;

            if (ix + 3 > A.size()) {
                break;
            }

            for (int i = ix; i < ix + 3; i++) {

                p += A[i];
                z++;
                if (z == 3)
                    break;
            }
            perimeter = p;

            p = p / 2;

            float a = (p - A[ix]) * (p - A[ix  + 1]) * (p - A[ix + 2]) * p;

            if (a <= 0) {
                p = 0;
                ix++;
                continue;
            }
            area = sqrt(a);
        }
        if (area == 0) {
            return 0;
        }
        return perimeter;
    }
};