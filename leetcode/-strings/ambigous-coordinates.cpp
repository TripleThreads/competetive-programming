//
// Created by segni on 20/02/2020.
//

class Solution {
public:
    vector<string> allPossible(string substr) {
        if (substr.length() == 1) {
            return {substr};
        }
        vector<string> possible;
        if (substr.length() > 1 && substr.at(0) != '0') {
            possible.push_back(substr);
        }
        for (int i = 1; i < substr.length(); i++) {
            string beforePoint = substr.substr(0, i);
            string newS =  beforePoint + "." + substr.substr(i);
            if (beforePoint.length()  > 1 && beforePoint.at(0) == '0' || newS.at(newS.length() - 1) == '0') {
                continue;
            }
            possible.push_back(newS);
        }
        return possible;
    }

    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;
        S = S.substr(1, S.length() - 2);
        for (int i = 1; i < S.length(); i++) {
            string rsubs = S.substr(i);
            string lsubs = S.substr(0, i);
            auto left = allPossible(lsubs);
            auto substr = allPossible(rsubs);
            for (auto l : left) {
                for (auto r : substr) {
                    result.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return result;
    }
};