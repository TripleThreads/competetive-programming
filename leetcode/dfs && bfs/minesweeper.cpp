//
// Created by segni on 01/02/2020.
//

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int, int>> que;
        set<pair<int, int>> visited;

        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        que.push({click[0], click[1]});

        int n = board.size(), m = board[0].size();
        int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if (board[x][y] != 'E')
                continue;

            for (auto d : dir) {
                int xi = x + d[0];
                int yi = y + d[1];

                if (xi < 0 || yi < 0 || xi >= n || yi >= m || board[xi][yi] != 'E' && board[xi][yi] != 'M')
                    continue;

                if (board[xi][yi] == 'M')
                    board[x][y] = board[x][y] == 'E' ? '1' : ++board[x][y];
            }
            if (board[x][y] == 'E') {

                board[x][y] = 'B';

                for (auto d: dir) {
                    int xi = x + d[0];
                    int yi = y + d[1];

                    if (xi < 0 || yi < 0 || xi >= n || yi >= m || board[xi][yi] != 'E' && board[xi][yi] != 'M')
                        continue;
                    que.push({xi, yi});
                }
            }

            visited.insert({x, y});
        }
        return board;
    }
};