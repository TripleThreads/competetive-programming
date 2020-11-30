//
// Created by segni on 30/11/2020.
//

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int a = 0, b = 0;
        size_t maxLen = 0;
        for (char c : seq) {
            if (c == '(') {
                if (a < b)
                    a++, res.push_back(0);
                else
                    b++, res.push_back(1);
            }
            else {
                if (a >= b)
                    a--, res.push_back(0);
                else
                    b--, res.push_back(1);
            }
        }
        return res;
    }
};