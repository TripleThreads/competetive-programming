//
// Created by segni on 16/02/2020.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        long long int dp[n + 1];
        dp[0] = nums[0];
        dp[n] = INT_MIN;
        long long int maxProd = dp[0];
        for (int i = 1; i < n; i++) {
            int pre = dp[i - 1] ? dp[i - 1] : 1;
            dp[i] = nums[i] * pre;
            maxProd = max(maxProd, dp[i]);
        }

        int den = n;
        for (int i = 0; i < n; i++) {
            if (dp[i] < 0 && dp[i] > dp[den])
                den = i;
            if (dp[i] == 0)
                den = n;
            if (i > den)
                maxProd = max(maxProd, dp[i] / dp[den]);
        }
        return maxProd;
    }
};