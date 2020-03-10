//
// Created by segni on 10/03/2020.
//

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_set<int> visited;
        vector<vector<int>> subord(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                subord[manager[i]].push_back(i);
        }
        queue<pair<int, int>> que;
        que.push({headID, informTime[headID]});
        int time = 0;

        while (visited.size() < n) {
            auto [cur, cost] = que.front();
            visited.insert(cur);
            que.pop();
            for (int i : subord[cur]) {
                int nCost = cost + informTime[i];
                que.push({i, nCost});
                time = max(time, nCost);
            }
        }
        return time;
    }
};