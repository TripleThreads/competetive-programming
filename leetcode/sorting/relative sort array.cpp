//
// Created by segni on 21/12/2019.
//

class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count_array[1001] = {0};

        vector<int> ar;

        for (int i = 0; i < arr1.size(); i++) {
            count_array[arr1[i]]++;
        }

        int a_ix = 0;

        for (int i : arr2) {
            for (int j = 0; j < count_array[i]; j++) {
                ar.push_back(i);
            }
            count_array[i] = 0;
        }
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < count_array[i]; j++) {
                ar.push_back(i);
            }
        }
        return ar;
    }


};