//
// Created by segni on 25/01/2020.
//

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> que;

        int fresh = 0, n = grid.size(), m = grid[0].size();

        for (int x = 0; x < grid.size();x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == 2)
                    que.push({x, y});
                else if (grid[x][y] == 1)
                    fresh++;
            }
        }
        if (fresh == 0) return 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        while (!que.empty() && fresh > 0) {
            count++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto pr = que.front();
                que.pop();
                for (auto dir : dirs) {
                    int x = pr[0] + dir[0];
                    int y = pr[1] + dir[1];
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 2 || grid[x][y] == 0)
                        continue;
                    grid[x][y] = 2;
                    que.push({x, y});
                    fresh--;
                }
            }
        }
        return 0 == fresh ? count : -1;
    }
};