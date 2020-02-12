//
// Created by segni on 12/02/2020.
//

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        map<int, int> minSky, row;
        int  n = grid.size(), m = grid[0].size();
        int before = 0;
        for (int i = 0; i < n; i++) {
            int mx = INT_MIN;
            for (int j = 0; j < m; j++) {
                mx = max(mx, grid[i][j]);
                before += grid[i][j];
            }
            minSky[i] = mx;
        }
        for (int i = 0; i < m; i++) {
            int mx = INT_MIN;
            for (int j = 0; j < n; j++) {
                mx = max(mx, grid[j][i]);
            }
            row[i] = mx;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = min(minSky[i], row[j]);
                cout << grid[i][j] << " ";
                sum += grid[i][j];
            }
            cout << endl;
        }
        return sum  - before;
    }
};