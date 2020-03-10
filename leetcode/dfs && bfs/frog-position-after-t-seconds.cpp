//
// Created by segni on 10/03/2020.
//

struct Jump {
    int time;
    int index;
    double pro; // probability
    Jump(int i, int t, double p) : index(i), time(t), pro(p){}
};
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> tree(n + 1);
        vector pos(n + 1, -1);
        for (auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        if (target == 1 && (t == 0 || tree[1].size() <= 1 && n <= 2))
            return 1.0;

        queue<Jump> que;
        que.push(Jump(1, 0, 1));
        unordered_set<int> visited;
        while(!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (t <= cur.time) {
                if (cur.index == target)
                    return cur.pro;
                continue;
            }
            visited.insert(cur.index);
            int size = tree[cur.index].size();
            if (cur.index != 1 && size > 1) // just decrease incoming edge(parent)
                size--;

            for (int i : tree[cur.index]) {
                if (visited.count(i) || t <= cur.time) continue;

                double prob = cur.pro * 1 / (double) size;
                que.push(Jump(i, cur.time + 1, prob));
                if (tree[i].size() == 1 && i == target) { // if it has only has 1 edge [leaf]
                    return prob;
                }
            }
        }
        return 0.0;
    }
};