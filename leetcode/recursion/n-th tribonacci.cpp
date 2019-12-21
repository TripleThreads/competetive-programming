//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int trib(int n, int a, int b, int c) {
        if (n <= 1) return n;
        if (n == 2) return c;
        return trib(n - 1, b, c, a + b + c);
    }

    int tribonacci(int n) {
        return trib(n, 0, 1, 1);
    }
};