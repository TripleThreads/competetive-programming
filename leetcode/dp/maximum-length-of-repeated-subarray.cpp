//
// Created by segni on 10/02/2020.
//

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int MAX = 0;
        int n = A.size();
        int m = B.size();
        int dp[n + 2][m + 2];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                MAX = max(dp[i][j], MAX);
            }
        }
        return MAX;
    }
};