//
// Created by segni on 01/01/2020.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int inc = 0;

        while (n >= 5) {
            n = n / 5;
            inc += n;
        }

        return inc;
    }
};