//
// Created by segni on 01/01/2020.
//

class Solution {
public:
    string complexNumberMultiply(string a, string b) {

        int a_natural = stoi(a.substr(0, a.find('+')));
        int a_compl = stoi(a.substr(a.find('+') + 1, a.find('i')));

        int b_natural = stoi(b.substr(0, b.find('+')));
        int b_compl = stoi(b.substr(b.find('+') + 1, b.find('i')));

        int n = a_natural * b_natural - a_compl * b_compl;

        int c = a_compl * b_natural + b_compl * a_natural;

        string res = "";

        res.append(to_string(n) + "+" + to_string(c) + "i");

        return res;
    }
};