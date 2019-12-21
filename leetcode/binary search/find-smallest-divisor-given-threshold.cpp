//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    unsigned int doSum(vector<int>& nums, int mid) {
        unsigned int sum = 0;
        for (int i  : nums) {
            sum += (i / mid);
            if (i % mid != 0) {
                sum++;
            }
        }
        return sum;
    }
    int binarySearch(vector<int> &nums, unsigned int l, unsigned int r, int x) {
        if (r >= l) {
            unsigned int mid = l + (r - l) / 2;
            unsigned int sum = doSum(nums, mid);

            if (sum <= x && doSum(nums, mid - 1) > x)
                return mid;

            if (sum <= x) {
                return binarySearch(nums, l, mid - 1, x);
            }

            return binarySearch(nums, mid + 1, r, x);
        }

        return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        unsigned int sum = 0;
        for (int i : nums)
            sum += i;
        if (threshold > sum) return 1;

        int mid = binarySearch(nums, 2, sum, threshold);
        return mid;
    }
};