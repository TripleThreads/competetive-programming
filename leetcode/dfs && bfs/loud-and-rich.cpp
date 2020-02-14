//
// Created by segni on 14/02/2020.
//

class Solution {
public:

    vector<int> memo;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> adj;
        for (auto v : richer)
            adj[v[1]].push_back(v[0]);

        memo = vector<int> (quiet.size(), INT_MIN);
        for (int i = 0; i < quiet.size(); i++) {
            dfs(i, quiet, adj);
        }
        return memo;
    }

    int dfs(int i, vector<int>& quiet, unordered_map<int, vector<int>> &adj) {
        if (memo[i] >= 0) return memo[i];
        memo[i] = i;
        for (int j : adj[i]) {
            if (quiet[memo[i]] > quiet[dfs(j, quiet, adj)])  {
                memo[i] = memo[j];
            }
        }
        return memo[i];
    }
};