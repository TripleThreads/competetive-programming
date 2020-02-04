//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        unordered_map<int, int> hash_map;
        vector<int> endPts;
        for (auto in : intervals) {
            if (hash_map.count(in[1]))
                hash_map[in[1]] = max(hash_map[in[1]], in[0]);
            else {
                hash_map[in[1]] = in[0];
                endPts.push_back(in[1]);
            }
        }
        int count = 0, mn = INT_MIN;
        sort(endPts.begin(), endPts.end());
        for (int pt : endPts) {
            if (hash_map[pt] >= mn) {
                mn = pt;
                count++;
            }
        }
        return intervals.size() - count;
    }
};