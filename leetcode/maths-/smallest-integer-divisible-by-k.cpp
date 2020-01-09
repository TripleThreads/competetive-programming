//
// Created by segni on 09/01/2020.
//

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0)
            return -1;
        int num = 1,inc = 1;

        while (inc <= K) {
            if (num % K == 0)
                return inc;
            num = num * 10 + 1;
            num = num % K;
            inc++;
        }
        return -1;
    }

};