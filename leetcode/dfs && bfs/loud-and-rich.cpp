//
// Created by segni on 14/02/2020.
//

class Solution {
public:
    int dfs(int index, vector<int>& quiet, unordered_map<int, vector<int>> &adj, vector<int> &memo) {
        if (memo[index] >= 0)
            return memo[index];

        memo[index] = index;
        for (int i : adj[index]) {
            if (quiet[memo[index]] > quiet[dfs(i, quiet, adj, memo)])  {
                memo[index] = memo[i];
            }
        }
        return memo[index];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> adj;
        for (auto v : richer)
            adj[v[1]].push_back(v[0]);

        vector<int> memo(quiet.size(), INT_MIN);
        for (int i = 0; i < quiet.size(); i++) {
            dfs(i, quiet, adj, memo);
        }
        return memo;
    }
};