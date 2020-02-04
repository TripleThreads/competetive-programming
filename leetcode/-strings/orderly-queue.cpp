//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    string orderlyQueue(string S, int K) {

        unordered_set<string> visited;
        if (K == 1) {
            string mn = S;
            while (!visited.count(S)) {
                visited.insert(S);
                char c = S.at(0);
                S = S.substr(1);
                S.push_back(c);
                if (S < mn)
                    mn = S;
            }
            return mn;
        }
        int letter[26] = {0};
        for (char c : S) {
            letter[c - 'a']++;
        }
        string res;
        for (int i = 0; i < 26; i++) {
            if (letter[i] > 0)
                res += string(letter[i], (char) (i + 'a'));
        }

        return res;
    }
};