//
// Created by segni on 12/02/2020.
//

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count = 1;
        int size = 0;

        for (char c : S) {
            int curSize =  widths[c - 'a'];
            if (size + curSize > 100) {
                size = curSize;
                count++;
            }
            else
                size += curSize;
        }

        return {count, size};
    }
};