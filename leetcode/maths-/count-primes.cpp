//
// Created by segni on 31/12/2019.
//

class Solution {
public:
    int countPrimes(int n) {
        int inc = 0;
        if (n <= 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;
        int sq = sqrt(n);
        for (int i = 2; i <= sq; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        for (bool prime: primes)
            if (prime)
                inc++;

        return inc;
    }
};