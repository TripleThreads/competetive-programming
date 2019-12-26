//
// Created by segni on 26/12/2019.
//
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        priority_queue<pair<int, int>> que;

        unordered_map<int, int> dict;

        for (int num: nums) {
            dict[num]++;
        }

        for (auto const& [key, value] : dict) {
            que.push(make_pair(value, key));
        }

        for (int i = 0; i < k; i++) {
            result.push_back(que.top().second);
            que.pop();
        }

        return result;
    }
};