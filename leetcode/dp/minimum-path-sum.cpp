//
// Created by segni on 05/02/2020.
//

class Solution {
public:
    int minPathSum(vector<vector<int>>& path) {
        if (path.size() == 0)
            return 0;
        int r = path.size();
        int c = path[0].size();

        int dp[r][c];
        dp[0][0] = path[0][0];

        for (int i = 1; i < r; i++)
            dp[i][0] = dp[i - 1][0] + path[i][0];

        for (int i = 1; i < c; i++)
            dp[0][i] = dp[0][i - 1] + path[0][i];

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = path[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[r - 1][c - 1];
    }
};