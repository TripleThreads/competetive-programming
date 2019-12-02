//
// Created by segni on 02/12/2019.
//

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

        int size = R * C;

        vector<vector<int>> res[size];

        vector<vector<int>> ans(size);

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                res[abs(r - r0) + abs(c - c0)].push_back({r, c});
            }
        }
        int index = 0;

        for (int i = 0; i < size; i++) {
            // remove from the linked list
            while(!res[i].empty()) {
                ans[index] = *(res[i].begin());
                res[i].erase(res[i].begin());
                index++;
            }
        }

        return ans;
    }
};