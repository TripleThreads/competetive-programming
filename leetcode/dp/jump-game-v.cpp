//
// Created by segni on 06/02/2020.
//

class Solution {
public:
    unordered_map<int, int> mem;
    int MAX = 1;
    int dp(vector<int> arr, int index, int k, int n) {
        int curMax = 0;
        mem[index] = 1;
        for (int i = index - 1; i >= index - k; i--) {
            if (i < 0 || arr[i] >= arr[index]) break;
            if (arr[i] < arr[index])
                curMax = max(mem[i], curMax);
        }
        for (int i = index + 1; i <= index + k; i++) {
            if (i >= n || arr[i] >= arr[index])
                break;
            if (mem.count(i))
                curMax = max(curMax, mem[i]);
            else
                curMax = max(curMax, dp(arr, i, k, n));
        }
        mem[index] += curMax;
        MAX = max(MAX, mem[index]);
        return mem[index];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            dp(arr, i, d, n);
        return MAX;
    }
};