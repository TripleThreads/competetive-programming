//
// Created by Segni on 24/02/2020.
//

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> neighbours(n);
        vector<unordered_set<int>> count(n);

        for (auto edge : edges) {
            if (threshold >= edge[2]) {
                neighbours[edge[0]].push_back({edge[1], edge[2]});
                neighbours[edge[1]].push_back({edge[0], edge[2]});
            }
        }

        for (int i = 0; i < n; i++) {
            int visited[n];
            memset(visited, 10000, sizeof(visited));
            queue<pair<int, int>> que;
            que.push({i, 0});
            while (!que.empty()) {
                auto cur = que.front();
                que.pop();
                if (visited[cur.first] < cur.second) {
                    continue;
                }
                visited[cur.first] = cur.second;
                for (auto [city, w] : neighbours[cur.first]) {
                    if (w + cur.second <= threshold && visited[city] >= w + cur.second) {
                        que.push({city, w + cur.second});
                        count[i].insert(city);
                    }
                }
            }
        }
        int minCity = 0;
        for (auto i  = 0; i < n; i++) {
            if (count[i].size() <= count[minCity].size()) {
                minCity = i;
            }
        }
        return minCity;
    }
};