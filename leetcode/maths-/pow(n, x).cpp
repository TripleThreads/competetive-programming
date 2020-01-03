//
// Created by segni on 03/01/2020.
//

class Solution {
public:
    double myPow(double x, int n) {

        long int N = n;
        double base = 1;

        N = (N > 0) ? N : -1 * N;

        if (abs(x) == 1.0)
            return (N % 2 == 0) ? abs(x) : x;

        if (n < 0)
            x = 1/x;

        for (int i = 0; i < N; i++) {

            if (base == 0)
                break;

            if (i > 0 && N - i > i) {
                base *= base;
                i += i - 1;
            }
            else
                base *= x;
        }
        return base;
    }
};