//
// Created by segni on 06/02/2020.
//

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
        map<int, int> m;
        for (int row = 0; row < matrix.size(); row++) {
            m[row] = 0;
            for (int i : matrix[row]) {
                if (i == 1) {
                    m[row]++;
                }
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (auto [key, v] : m) {
            que.push({v, key});
        }
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = que.top().second;
            que.pop();
        }
        return result;
    }
};