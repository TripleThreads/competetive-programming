//
// Created by segni on 12/02/2020.
//

struct pair_hash {
    inline size_t operator() (const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<pair<int, int>, unordered_set<int>, pair_hash> visited; // {sum, len} = {1, 2, 3, 4};
        unordered_set<pair<int, int>, pair_hash> endPoints;
        visited[{0, 0}] = {};

        int n = A.size();
        int sum = 0; // total sum
        for (int i : A)
            sum += i;

        for (int i = 1; i <= n / 2; i++)
            if (i * sum % n == 0)
                endPoints.insert({i * sum / n, i});

        if (endPoints.size() == 0) return false;
        // bfs
        queue<pair<int, int>> que;
        que.push({0, 0});

        while (!que.empty()) {
            auto node = que.front();
            que.pop();
            for (int i = 0; i < n; i++) {
                if (!visited[node].count(i)) {
                    int sum = node.first + A[i];
                    int len = node.second + 1;
                    if (endPoints.count({sum, len}))
                        return true;

                    if (!visited.count({sum, len}) && len <= n / 2) {
                        que.push({sum, len});
                        visited[{sum, len}] = visited[node];
                        visited[{sum, len}].insert(i);
                    }
                }
            }
        }
        return false;
    }
};