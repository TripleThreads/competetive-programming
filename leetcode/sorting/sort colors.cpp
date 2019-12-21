//
// Created by segni on 21/12/2019.
//
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;

        for (int i : nums) {
            if (i == 0)
                r++;
            if (i == 1)
                w++;
            if (i == 2)
                b++;
        }

        int ix = 0;
        for (int i = 0; i < r; i++) {
            nums[ix++] = 0;
        }
        for (int i = 0; i < w; i++) {
            nums[ix++] = 1;
        }
        for (int i = 0; i < b; i++) {
            nums[ix++] = 2;
        }
    }
};
