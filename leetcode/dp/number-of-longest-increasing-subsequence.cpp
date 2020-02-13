//
// Created by segni on 14/02/2020.
//

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> dp;
        for (int i = n - 1; i >= 0; i--) {
            int len = 1, occ = 1;
            for (int j = i; j < n; j++) {
                if (nums[i] < nums[j]) {
                    auto [l, o] = dp[j];
                    if (len < 1 + l) {
                        len = 1 + l;
                        occ = o;
                    }
                    else if (len == 1 + l) {
                        occ += o;
                    }
                }
            }
            dp[i] = {len, occ};
        }
        int maxLen = 0, maxOcc = 0;
        for (auto [key, val] : dp) {
            auto [len, occ] = val;
            if (len > maxLen) {
                maxLen = len;
                maxOcc = occ;
            }
            else if (len == maxLen) {
                maxOcc += occ;
            }
        }
        return maxOcc;
    }
};