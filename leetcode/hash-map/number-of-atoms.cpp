//
// Created by segni on 21/01/2020.
//

class Solution {
public:
    int getDigit(string s, int i) { // get digit starting from the last term
        int j = i;
        while (i < s.length() && isdigit(s.at(i)))
            i--;
        return stoi(s.substr(++i, j));
    }
    string countOfAtoms(string formula) {
        map<string, int> count;
        stack<int> subs; // holds subscripts
        subs.push(1);
        int n = formula.size(), d = 1;
        for (int i = n - 1; i >= 0; i--) {
            char c = formula.at(i);
            if (c == ')')
                subs.push(d * subs.top());

            else if (c == '(')
                subs.pop();

            else if (isdigit(c)) {
                d = getDigit(formula, i);
                i -= log10(d) - 1; // if the number is more than one digit
                continue;
            }
            else if (islower(c)) // if it is lowercase it will take the preceding char too. ex. Br
                count[formula.substr(--i, 2)] += d * subs.top();
            else // if it is upper case simply increment ex. H
                count[formula.substr(i, 1)] += d * subs.top();
            d = 1;
        }
        string result;
        for (auto const & [k, v] : count) {
            result.append(k);
            result += v > 1 ? to_string(v) : "";
        }
        return result;
    }
};