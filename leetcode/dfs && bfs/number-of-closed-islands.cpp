//
// Created by segni on 25/01/2020.
//

struct pair_hash {
    inline size_t operator() (const pair<int, int> &pr) const {
        return pr.first ^ pr.second;
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), inc = 0;

        unordered_set<pair<int, int>, pair_hash> visited;

        queue<pair<int, int>> que;

        for (int i = 1; i < n - 1; i++) {

            for (int j = 1; j < m - 1; j++)

                if (grid[i][j] == 0)
                    que.push({i, j});
        }
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto pr = que.front();
            que.pop();

            queue<pair<int, int>> sub;

            if (visited.find(pr) == visited.end())
                sub.push(pr);

            bool closed = true;
            while (!sub.empty()) {
                pr = sub.front();
                sub.pop();
                visited.insert(pr);
                for (auto d : dirs) {
                    int x = pr.first + d[0];
                    int y = pr.second + d[1];

                    if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && grid[x][y] == 0)
                        closed = false;

                    else if (grid[x][y] == 0 && visited.find({x, y}) == visited.end()) {
                        sub.push({x, y});
                    }
                }
                if (sub.empty() && closed)
                    inc++;
            }
        }

        return inc;
    }
};