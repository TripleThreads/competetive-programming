//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {

        int total = 0;

        while (arr.size() > 1) {
            int mn = INT_MAX, in = 0;
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i]  * arr[i + 1] < mn) {
                    mn = arr[i] * arr[i + 1];
                    in = i;
                }
            }
            total += arr[in] * arr[in + 1];
            int inc = arr[in] > arr[in + 1] ? 1 : 0;
            arr.erase(arr.begin() + in + inc);
        }
        return total;
    }
};