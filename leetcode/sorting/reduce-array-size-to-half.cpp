//
// Created by segni on 06/02/2020.
//

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> umap;
        int size = arr.size();

        for (int a : arr)
            umap[a]++;

        priority_queue<int> que;

        for (auto [k, v] : umap)
            que.push(v);

        int n = 0, count = 0;
        while (n < size / 2) {
            n += que.top();
            que.pop();
            count++;
        }

        return count;
    }
};