//
// Created by segni on 11/02/2020.
//
struct pair_hash{
    inline size_t operator() (const pair<long int, long int> & pr ) const {
        return pr.first ^ pr.second;
    }
};

class Solution {
public:
    unordered_map<pair<long int, long int>, long long int, pair_hash> mem;
    long long int dp(int d, int f, int target) {
        if (d == 0) return target > 0 ? 0 : 1;
        if (mem.count({d, target})) return mem[{d, target}];
        long long int total = 0;
        for (int i = max(0, target - f); i < target; i++)
            total = (total + dp(d - 1, f, i)) % 1000000007;
        mem[{d, target}] = total;
        return mem[{d, target}];
    }

    int numRollsToTarget(int d, int f, int target) {
        return dp(d, f, target);
    }
};