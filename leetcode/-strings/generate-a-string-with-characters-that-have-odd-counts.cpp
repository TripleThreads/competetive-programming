//
// Created by segni on 10/03/2020.
//

class Solution {
public:
    string generateTheString(int n) {
        string res = string(n, 'a');
        if (n % 2 == 0) {
            res.pop_back();
            res.push_back('b');
        }
        return res;
    }
};