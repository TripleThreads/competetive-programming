//
// Created by segni on 06/02/2020.
//

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--) {

            for (int j = 0; j < triangle[i].size(); j++) {
                int cur = triangle[i][j];
                int right = cur + triangle[i + 1][j + 1];
                int left = cur + triangle[i + 1][j];
                triangle[i][j] = min({left, right});
            }
        }
        return triangle[0][0];
    }
};