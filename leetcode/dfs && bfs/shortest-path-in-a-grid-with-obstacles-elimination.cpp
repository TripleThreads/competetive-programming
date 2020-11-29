struct Node {
    int step, x, y, k;
    Node(int s, int xx, int yy, int kk): step(s), x(xx), y(yy), k(kk){}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<Node> que;
        auto s = Node(0, 0, 0, k);
        que.push(s);
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> seen(n, vector<int>(m, -1)), dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!que.empty()) {

            auto f = que.front();
            que.pop();

            if (f.x == n - 1 && f.y == m - 1) return f.step;
            if (seen[f.x][f.y] >= f.k || f.k < 0) continue;
            seen[f.x][f.y] = f.k;
            for (auto &d: dirs) {
                int x = f.x + d[0];
                int y = f.y + d[1];
                if (x >= 0 && y >= 0 && x < n && y < m && seen[x][y] < f.k - grid[x][y] && f.k - grid[x][y] >= 0)
                    que.push(Node(f.step + 1, x, y, f.k - grid[x][y]));
            }
        }
        return -1;
    }
};