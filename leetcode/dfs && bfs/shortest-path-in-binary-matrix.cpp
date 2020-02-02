//
// Created by segni on 02/02/2020.
//

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> que; // x, y, cost;
        if (grid[0][0] == 0)
            que.push({0, 0, 1});

        int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        while (!que.empty()) {
            auto point = que.front();
            que.pop();

            if (point[0] == n - 1 && point[1] == n - 1)
                return point[2];

            for (auto d : dir) {
                int xi = point[0] + d[0];
                int yi = point[1] + d[1];

                if (xi < 0 || yi < 0 || xi >= n || yi >= n || grid[xi][yi] != 0)
                    continue;
                grid[xi][yi] = 1;
                que.push({xi, yi, point[2] + 1});
                if (xi == n - 1 && yi == n - 1)
                    return point[2] + 1;
            }

        }
        return -1;
    }
};