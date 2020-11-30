//
// Created by segni on 30/11/2020.
//

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> size(n + 2, 0), res(n, 0);
        for (auto &v : bookings) {
            size[v[0]] += v[2];
            size[v[1] + 1] -= v[2];
        }
        int tot = 0;

        for (int j = 1; j <= n; j++) {
            tot += size[j];
            res[j - 1] += tot;
        }
        return res;
    }
};

/*
1, 2, 3, 4, 5
10 -10


*/