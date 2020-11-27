class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<char>>& grid, int px, int py, int cx, int cy, bool first, vector<vector<int>> &dirs) {
        if (cx < 0 || cy < 0 || cx == grid.size() || cy == grid[0].size()) return;
        if (!first && isupper(grid[cx][cy])) {
            cycle = true;
            return;
        }
        if (cx == px && cy == py || isupper(grid[cx][cy])) return;
        grid[cx][cy] = toupper(grid[cx][cy]);
        for (auto &d : dirs) {
            int i = d[0] + cx;
            int j = d[1] + cy;
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
                if (toupper(grid[i][j])  == grid[cx][cy] && !(i == px && j == py))
                    dfs(grid, cx, cy, i, j, false, dirs);
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(!cycle)
                    dfs(grid, -1, -1, i, j, true, dirs);
                else
                    return true;
            }
        }
        return false;
    }
};
