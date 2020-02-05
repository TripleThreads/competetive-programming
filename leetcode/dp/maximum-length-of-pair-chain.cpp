//
// Created by segni on 05/02/2020.
//

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();
        int dp[size];
        dp[0] = 1;

        vector<pair<int, int>> sorted;
        for (auto pair : pairs)
            sorted.push_back({pair[0], pair[1]});

        sort(sorted.begin(), sorted.end());
        int totalMax = 0;
        for (int i = 0; i < size; i++) {
            int curMax = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (sorted[j].second < sorted[i].first) {
                    curMax = max(curMax, dp[j]);
                    break;
                }
            }
            dp[i] = 1 + curMax;
            totalMax = max(dp[i], totalMax);
        }
        return totalMax;
    }
};