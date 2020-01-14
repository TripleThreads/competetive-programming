//
// Created by segni on 14/01/2020.
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um; // stores elements with its index

        int i = 0;
        for (int num: nums) {
            if (um.find(num) == um.end()) { // if we haven't visited it before
                um[num] = i;
            }
            else {
                int in = um[num]; // get index

                if (i - in <= k)
                    return true;
                um[num] = i;
            }
            i++;
        }

        return false;
    }
};