//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> blue(n), red(n);

        for (auto r : red_edges)
            red[r[0]].push_back(r[1]);

        for (auto b : blue_edges)
            blue[b[0]].push_back(b[1]);

        vector<int> result(n, -1);
        result[0] = 0;

        // red True, and blue False
        map<pair<int, bool>, int> mp;
        queue<pair<int, bool>> que;

        que.push({0, true});
        que.push({0, false});
        mp[{0, true}] = 0;
        mp[{0, false}] = 0;

        while (!que.empty()) {
            auto pr = que.front();
            que.pop();

            auto neighbour = pr.second ? red[pr.first] : blue[pr.first];
            for (auto n : neighbour) {
                if (mp.count({n, !pr.second})) continue;
                mp[{n, !pr.second}] += 1 + mp[pr];
                que.push({n, !pr.second});
            }
        }
        for (int i = 1; i < n; i++) {
            auto r = mp.find({i, false});
            auto b = mp.find({i, true});
            if (r != mp.end() && b != mp.end())
                result[i] = min(r->second, b->second);

            else if (r != mp.end() || b != mp.end())
                result[i] = r == mp.end() ? b->second : r->second;
        }
        return result;
    }
};