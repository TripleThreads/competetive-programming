//
// Created by segni on 31/12/2019.
//

class Solution {
public:
    bool checkPerfectNumber(int num) {

        if (abs(num) == 1) return false;

        int sq = sqrt(num), sum = 1;

        for (int i = 2; i <= sq; i++) {
            if (num % i == 0) {
                sum += num / i;
                sum += i;
            }
        }

        return sum == num;
    }
};