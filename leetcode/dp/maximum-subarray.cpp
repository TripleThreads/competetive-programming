//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm
        int sum = 0, curMax = INT_MIN;
        for (int i : nums) {
            sum += i;
            sum = max(sum, i);
            curMax = max(curMax, sum);
        }
        return curMax;
    }
};