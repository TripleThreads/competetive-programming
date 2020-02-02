//
// Created by segni on 02/02/2020.
//

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), res = -1;
        int mat[n][n] = {0};

        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mat[i][j] = -1; // changed land mark to -1
                    que.push({i, j});
                }
            }
        }
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            for (auto d : dir) {
                int xi = x + d[0];
                int yi = y + d[1];
                if (xi < 0 || yi < 0 || xi >= n || yi >= n || mat[xi][yi] != 0)
                    continue;

                if (mat[x][y] == -1)
                    mat[xi][yi] = 1;
                else {
                    mat[xi][yi] = mat[x][y] + 1;
                    res = max(res, mat[xi][yi]);
                }
                que.push({xi, yi});
            }
        }
        return res;
    }
};