//
// Created by segni on 11/03/2020.
//
class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> elv;
        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > 0) {
                if (!elv.empty()) {
                    int curHeight = 0;
                    while (!elv.empty() && elv.top().second < height[i]) {
                        auto [ind, h] = elv.top();
                        total += (min(h, height[i]) - curHeight) * (i - ind - 1);
                        curHeight = min(h, height[i]);
                        elv.pop();
                    }
                    if (!elv.empty()) {
                        auto [ind, h] = elv.top();
                        total += (min(height[i], h) - curHeight) * (i - ind - 1);
                    }
                }
                elv.push({i, height[i]});
            }
        }
        return total;
    }
};