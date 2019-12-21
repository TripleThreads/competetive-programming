//
// Created by segni on 21/12/2019.
//

class Solution {
public:

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        map<int, int> count;
        vector<int> rearranged;

        int max_ix; // some random value at first

        int max_count = 0;

        for (int i : barcodes) {

            count[i]++;

            if (count[i] > max_count) {
                max_ix = i;
                max_count = count[max_ix];
            }
        }
        // the idea is if there is number which is greater than maximum index count
        // we can separate numbers and put between those big numbers

        vector<int> sub_codes[max_count]; // excluding the max
        int index = 0;

        for (auto &code: count) {
            if (code.first == max_ix) continue;

            while (code.second-- > 0) {
                sub_codes[(index++) % max_count].push_back(code.first);
            }
        }
        for (int i = 0; i < max_count; i++) {
            rearranged.push_back(max_ix);
            rearranged.insert(rearranged.end(), sub_codes[i].begin(), sub_codes[i].end());
        }
        return rearranged;
    }
};