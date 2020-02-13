//
// Created by segni on 13/02/2020.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;

        int n = nums.size();
        int dp[n];
        int maxSize = 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i; j < n; j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxSize = max(dp[i], maxSize);
                }
            }
        }
        return maxSize;
    }
};