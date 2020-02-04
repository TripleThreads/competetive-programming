//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>umap;
        unordered_set<int> uset;

        for (int i : arr)
            umap[i]++;

        for (auto [key, value] : umap)
            uset.insert(value);

        return uset.size() == umap.size();
    }
};