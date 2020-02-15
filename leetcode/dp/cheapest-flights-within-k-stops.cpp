//
// Created by segni on 15/02/2020.
//

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> all(n); // available flights with stop and price
        unordered_map<int, int> cost;

        for (auto vec : flights)
            all[vec[0]].push_back({vec[1], vec[2]});
        queue<vector<int>> que;
        que.push({src, 0, 0}); // src, stops, price
        int minPrice = INT_MAX;
        while (!que.empty()) {
            auto point = que.front();
            que.pop();

            if (point[2] > minPrice)
                continue;

            for (auto [d, p] : all[point[0]]) {
                if (d == dst && point[1] <= K)
                    minPrice = min(minPrice, point[2] + p);

                int pr = point[2] + p;
                int br = point[1] + 1;

                if (cost.count(d) && cost[d] <= pr)
                    continue;

                if (br <= K)
                    que.push({d, br, pr});
            }
            cost[point[0]] = point[2];
        }
        return minPrice == INT_MAX ? -1 : minPrice;
    }
};