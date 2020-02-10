//
// Created by segni on 10/02/2020.
//

class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        for (int i = n/2; n > 1; i--) {
            if (n % i != 0) continue;
            count += n / i;
            n -= i * ((n / i) - 1);
        }
        return count;
    }
};