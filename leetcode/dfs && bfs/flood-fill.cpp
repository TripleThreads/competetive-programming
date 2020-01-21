struct pair_hash {
    inline size_t operator()(const pair<int,int> & pr) const {
        return pr.first * 31 + pr.second;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> que;
        unordered_set<pair<int, int>, pair_hash> visited;
        // bfs
        que.push(make_pair(sr, sc));
        int color = image[sr][sc], n = image.size(), m = image[0].size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto pr = que.front();
            que.pop();

            image[pr.first][pr.second] = newColor;

            if (visited.find(pr) != visited.end())
                continue;

            visited.insert(pr);

            for (auto d : dir) {
                int x = pr.first + d[0];
                int y = pr.second + d[1];
                if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != color)
                    continue;
                que.push({x, y});
            }
        }

        return image;
    }
};