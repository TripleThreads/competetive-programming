//
// Created by segni on 21/01/2020.
//

struct pair_hash {
    inline size_t operator() (const pair<int, int> &pr) const {
        return pr.first ^ pr.second;
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, pair_hash> coords;

        for (auto p : points)
            coords.insert({p[0], p[1]});

        int _min = INT_MAX;
        for (auto p: coords) {

            for (auto q: coords) {

                if (p.first == q.first || q.second == p.second)
                    continue;

                if (coords.count({p.first, q.second}) && coords.count({q.first, p.second}))
                    _min = min(_min, abs(q.first - p.first) * abs(q.second - p.second));
            }
        }
        return _min == INT_MAX ? 0 : _min;
    }
};