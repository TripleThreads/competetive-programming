//
// Created by segni on 13/01/2020.
//

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        vector<int> count(26, INT_MAX);
        vector<string> res;

        for (string str : A) {

            map<char, int> n;

            for (char c : str)
                n[c]++;

            for (int i = 0; i < 26; i++)
                count[i] = min(n[i + 'a'], count[i]);
        }

        for (int i = 0; i < 26; i++) {
            for (int v = 0; v < count[i]; v++)
                res.push_back(string(1, i + 'a'));
        }
        return res;
    }
};