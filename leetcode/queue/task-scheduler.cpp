//
// Created by segni on 25/01/2020.
//

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if (n == 0 || tasks.size() == 0) return tasks.size();
        unordered_map<char, int> count;

        priority_queue<pair<int, char>> pque;
        queue<pair<int, char>> sque;

        for (char c : tasks)
            count[c]++;

        for (auto const &[k, v] : count) {
            pque.push({v, k});
            count[k] = 0;
        }

        int inc = 0;
        char lastC;

        while (!pque.empty()) {
            auto prim = pque.top();
            pque.pop();
            count[prim.second] = inc;
            // how many idle is needed
            int idle = sque.empty() ? 0 : inc - count[sque.front().second];

            if (--prim.first > 0)
                sque.push(prim);

            if (pque.empty() && !sque.empty() && idle < n)
                inc += n - idle;

            if (sque.size() > n || pque.empty() && !sque.empty() || idle >= n) {
                pque.push(sque.front());
                sque.pop();
            }

            inc++;
        }

        return inc;
    }
};