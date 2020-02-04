//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        long int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};