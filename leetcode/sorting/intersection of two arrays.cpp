//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        map <int, int > unique;
        vector<int> vec;
        for (int i : nums1) {
            unique[i] = 1;
        }
        for (int j: nums2) {
            if (unique.find(j) != unique.end() && unique[j] == 1) {
                vec.push_back(j);
                unique[j] = 2;
            }
        }
        return vec;
    }
};