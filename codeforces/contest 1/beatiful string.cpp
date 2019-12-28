//
// Created by segni on 05/12/2019.
//
#include <iostream>

using namespace std;

int maxIndex(int exclude_prev, int exclude_next) {
    int max = -1;
    for (int i = 0; i < 3; i++) {
        if (exclude_prev == i || exclude_next == i) continue;
        return i;
    }
    return max;
}

string beautifulString() {
    string S;
    cin >> S;

    string result = "";

    if (S.length() == 0) {
        return result;
    }
    int ex_prev = 4;
    int it = 0;
    int exl_next = 4;
    for (char c : S) {
        if (it < S.length() - 1) {
            exl_next = S.at(it + 1) - 97;
        } else {
            exl_next = 4;
        }
        if (c == exl_next) return "-1";
        if (c != '?') {
            result.push_back(c);
            ex_prev = c - 97;
            if (it > 0 && c == S.at(it - 1)) return "-1";
        } else {
            int max_ix = maxIndex(ex_prev, exl_next);
            if (max_ix == -1) return "-1";
            result.push_back(max_ix + 97);

            ex_prev = max_ix;
        }
        it++;
    }
    return result;
}

int main() {
    int len;
    cin >> len;
    vector<string> result;
    for (int i = 0; i < len; i++) {
        cout << beautifulString() << endl;
    }
    return 0;
}
