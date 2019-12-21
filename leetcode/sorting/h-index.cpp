//
// Created by segni on 21/12/2019.
//

class Solution {
public:

    int max_num(vector<int> &array) {
        int max = 0;
        for (int num: array) {
            if (num > max)
                max = num;
        }
        return max;
    }

    int hIndex(vector<int>& citations) {

        vector<int> range(max + 1, 0);

        int arr_size = citations.size();

        int max = max_num(citations);

        int cit = 0;

        for (int i : citations) {
            for (int j = 1; j <= min(i, arr_size); j++) {
                range[j]++;
            }
        }

        for (int i = 0; i <= max; i++) {

            if (range[i] >= i)
                cit = i;
        }
        return cit;

    }
};