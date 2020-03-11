//
// Created by segni on 11/03/2020.
//

// cases
// [1, 3], [6, 9] -- > [2, 5]
// [1, 3], [6, 9] -- > [4, 5]
// [1, 3], [6, 9] -- > [2, 7]
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};

        int start = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> all, res;

        // divide and conquer
        if (start >= intervals[n - 1][0]) {
            all.insert(all.end(), intervals.begin(), intervals.end());
            all.push_back({start, end});
        }
        else {
            for (auto &inter : intervals) {
                if (start < inter[0]) {
                    all.push_back({start, end});
                    start = INT_MAX;
                }
                all.push_back(inter);
            }
        }
        res.push_back(all[0]);
        for (int i = 1; i <= n; i++) {
            if (res.back()[1] >= all[i][0]) {
                while (i <= n && res.back()[1] >= all[i][0])
                    i++;

                res.back()[1] = max(all[--i][1], res.back()[1]);
            }
            else {
                res.push_back(all[i]);
            }
        }

        return res;
    }
};