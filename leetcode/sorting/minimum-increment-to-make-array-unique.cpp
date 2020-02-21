//
// Created by segni on 21/02/2020.
//

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = 80001;
        int count[n];
        memset(count, 0, sizeof(count));

        int inc = 0;
        for (int i : A) {
            count[i]++;
        }

        for (int i = 0; i < n - 1; i++) {
            if (count[i] <= 1)
                continue;

            int diff = count[i] - 1;
            inc += diff;
            count[i + 1] += diff;
        }
        return inc;
    }
};