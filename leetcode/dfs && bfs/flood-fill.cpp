//
// Created by segni on 17/01/2020.
//
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
        while (!que.empty()) {
            auto pr = que.front();
            que.pop();

            image[pr.first][pr.second] = newColor;

            if (visited.find(pr) != visited.end())
                continue;

            visited.insert(pr);

            if (pr.first + 1 < n && image[pr.first + 1][pr.second] == color)
                que.push(make_pair(pr.first + 1, pr.second));

            if (pr.first > 0 && image[pr.first - 1][pr.second] == color)
                que.push(make_pair(pr.first - 1, pr.second));

            if (pr.second + 1 < m && image[pr.first][pr.second + 1] == color)
                que.push(make_pair(pr.first, pr.second + 1));

            if (pr.second > 0 && image[pr.first][pr.second - 1] == color)
                que.push(make_pair(pr.first, pr.second - 1));
        }

        return image;
    }
};
