//
// Created by segni on 29/02/2020.
//

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int totalCount = 0;
        for (int i = 0; i < n - 1; i++) {
            int firstLover = row[i] / 2;
            for (int j = 0; j < n; j++) {
                if (i != j && row[j] / 2 == firstLover && abs(j - i) > 1) {
                    totalCount++;
                    swap(row[i + 1], row[j]);
                    break;
                }
            }
        }
        return totalCount;
    }
};