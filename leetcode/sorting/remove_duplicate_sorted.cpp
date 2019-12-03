//
// Created by segni on 03/12/2019.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 1) return nums.size();

        int last = 0;

        for (int i  = 0; i < nums.size(); i++) {

            if (nums[i] != nums[last]) {
                nums[++last] = nums[i];
            }

        }

        if (last == nums.size() - 1) {
            nums.push_back(nums[nums.size() - 1]);
            return ++last;
        }

        nums[++last] = nums[nums.size() - 1];

        return last;
    }
};