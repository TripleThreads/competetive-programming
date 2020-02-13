//
// Created by segni on 14/02/2020.
//

class Solution {
public:
    int easy(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int dp[n + 1];
        dp[0] = nums[0];
        dp[1] = nums[1];

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            dp[i] = max(dp[i], (dp[i - 1] - nums[i - 1]) + nums[i]);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> temp1, temp2;
        for (int i = 1; i < n; i++)
            temp1.push_back(nums[i]);
        for (int i = 0; i < n - 1; i++)
            temp2.push_back(nums[i]);
        return max(easy(temp1), easy(temp2));
    }
};