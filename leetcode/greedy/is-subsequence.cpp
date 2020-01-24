//
// Created by segni on 24/01/2020.
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[s_ptr] == t[i])
                s_ptr++;
        }
        return s_ptr == s.length();
    }
};