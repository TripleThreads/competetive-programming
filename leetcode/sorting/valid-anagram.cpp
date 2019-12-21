//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ana_table;
        if (s.length() != t.length()) {
            return false;
        }
        for (int a = 0; a < s.length(); a++) {
            ana_table[s[a]]++;
            ana_table[t[a]]--;
        }
        for (char a: t) {
            if (ana_table[a] != 0)
                return false;
        }
        return true;
    }
};