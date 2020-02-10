//
// Created by segni on 10/02/2020.
//

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        unordered_map<int, int> mem;
        for (auto clip : clips)
            mem[clip[0]] = mem.count(clip[0]) ? max(clip[1], mem[clip[0]]) : clip[1];

        int n = mem.size();
        vector<pair<int, int>> vec;
        for (auto [i, f] : mem)
            vec.push_back({i,f});

        sort(vec.begin(), vec.end());
        if (vec[0].first != 0)
            return -1;
        else if (vec[0].first == 0 && vec[0].second >= T)
            return 1;

        int count = 1;
        for (int i = 0; i < n; i++) {
            int t = -1, curMax = vec[i].second;
            for (int j = 0; j < n && vec[j].first <= vec[i].second; j++) {
                if (vec[j].second > curMax) {
                    t = j;
                    curMax = vec[j].second;
                }
            }
            if (t == -1) return t;
            i = t - 1;
            count++;
            if (curMax >= T) return count;
        }
        return -1;
    }
};