//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;

        int count = 0;
        char lastCh = s.at(0);

        for (int i = 0; i < s.length(); i++) {

            char a = s.at(i);
            res.push_back(a);

            if (lastCh == a)
                count++;

            else {
                lastCh = a;
                count = 1;
            }

            if (count == k)
                while (count-- > 0) {
                    res.pop_back();
                }
        }
        if (res.length() == s.length())
            return res;

        return removeDuplicates(res, k);
    }
};