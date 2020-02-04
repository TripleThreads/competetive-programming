//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> m;
        for (auto d : dominoes) {
            int mi = min(d[0], d[1]);
            int ma = max(d[0], d[1]);
            m[{mi, ma}]++;
        }
        int count = 0;
        for (auto [k, v] : m) {
            if (v > 1)
                count+= (v * (v - 1) ) / 2;
        }

        return count;
    }
};