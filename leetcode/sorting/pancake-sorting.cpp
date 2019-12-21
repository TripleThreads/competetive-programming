//
// Created by segni on 21/12/2019.
//
class Solution {
public:

    void flip(vector<int>& A, int k) {
        for (int i = k - 1; i >= k / 2; i--) {
            swap(A[k - i - 1], A[i]);
        }
    }

    bool is_sorted(vector<int> &A, int size) {
        for (int i = 1; i < size; i++) {
            if (A[i - 1] > A[i])
                return false;
        }
        return true;
    }

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> k_list;
        int arr_size =  A.size();

        int right_ix = arr_size;

        int max_index = 0;

        while (!is_sorted(A, arr_size)) {

            if (A[right_ix - 1] < A[right_ix - 2]  ) {
                max_index = right_ix - 1;
            }

            if (A[0] > A[right_ix - 1]) {
                flip(A, right_ix);
                k_list.push_back(right_ix);
                right_ix = arr_size + 1;
                max_index = 0;
            }
            else if (right_ix == 2) {
                flip(A, max_index);
                k_list.push_back(max_index);
                right_ix = arr_size + 1;
                max_index = 0;
            }
            right_ix--;
        }
        return k_list;
    }
};
