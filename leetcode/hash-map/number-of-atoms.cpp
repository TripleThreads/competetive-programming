//
// Created by segni on 21/01/2020.
//

class Solution {
public:
    int getDigit(string s, int i) {
        int j = i;
        while (i < s.length() && isdigit(s.at(i)))
            i--;
        return stoi(s.substr(++i, j));
    }
    string countOfAtoms(string formula) {
        map<string, int> count;
        stack<int> stck;
        stck.push(1);

        int n = formula.size(), d = 1;
        for (int i = n - 1; i >= 0; i--) {

            char c = formula.at(i);

            if (c == ')')
                stck.push(d * stck.top());

            else if (c == '(')
                stck.pop();

            else if (isdigit(c)) {
                d = getDigit(formula, i);
                i -= log10(d) - 1;
                continue;
            }

            else if (islower(c))
                count[formula.substr(--i, 2)] += d * stck.top();

            else
                count[formula.substr(i, 1)] += d * stck.top();

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