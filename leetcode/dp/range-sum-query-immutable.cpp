//
// Created by segni on 05/02/2020.
//

class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
            dp.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return i > 0 ? dp[j] - dp[i - 1] : dp[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */