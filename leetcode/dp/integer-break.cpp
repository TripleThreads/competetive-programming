//
// Created by segni on 07/02/2020.
//

class Solution {
public:
    unordered_map<long long int, long long int> mem;
    int integerBreak(int n) {
        if (n < 4) return (n / 2) * (n - (n/2));
        int q = n / 3;
        int r = n % 3;
        if (r == 2) return pow(3, q) * r;
        return r == 0 ? pow(3, q) : pow(3, q - 1) * 4;
    }
};