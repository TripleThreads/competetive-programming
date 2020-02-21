//
// Created by segni on 21/02/2020.
//

struct swim {
    int val;
    pair<int, int> coord;
    swim(int v, int x, int y) : val(v), coord({x, y}) {}
};
struct less_than {
    bool operator()(swim const& a, swim const& b) const {
        return a.val > b.val;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<swim, vector<swim>, less_than> pque;

        unordered_set<int> visited;
        pque.push(swim(grid[0][0], 0, 0));
        visited.insert(grid[0][0]);
        int maxVal = 0, n = grid.size();
        pair<int, int> end = {n - 1, n - 1};
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pque.empty()) {
            auto cur = pque.top();
            pque.pop();
            auto val = cur.val;
            auto coord = cur.coord;
            maxVal = max(maxVal, val);

            if (coord == end) {
                return maxVal;
            }
            for (auto d : dir) {
                int x = coord.first + d[0];
                int y = coord.second + d[1];

                if (x < 0 || y < 0 || x >= n || y >= n || visited.count(grid[x][y])) {
                    continue;
                }
                pque.push(swim(grid[x][y], x, y));
            }
            visited.insert(val);
        }
        return -1;
    }
};