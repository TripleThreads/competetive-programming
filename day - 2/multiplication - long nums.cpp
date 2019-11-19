#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

/**
 * @user segni
 * multiply large numbers
 * */

using namespace std;

vector<string> multiply(const string &num_1, const string &num_2) {

    vector<string> total;

    int carry_on = 0;

    for (int index_num = num_1.length() - 1; index_num >= 0; index_num--) {

        int x = num_1.at(index_num) - 48;

        vector<long long int> temp;

        for (int index = num_2.length() - 1; index >= 0; index--) {

            int y = num_2.at(index) - 48;

            int z = x * y + carry_on;

            if (index_num == 0) {

                temp.insert(temp.begin(), 1, z);

            } else {
                temp.insert(temp.begin(), 1, z % 10);
            }

            carry_on = z / 10;
        }

        string padding = "0";

        for (long long int i: temp) {
            padding = to_string(stoll(padding) * 10 + i);
        }

        for (int a = 0; a < num_1.length() - index_num - 1; a++) {
            padding.append("0");
        }

        total.insert(total.begin(), 1, padding);
    }
    return total;
}

void input() {

    string num_1, num_2;

    cin >> num_1 >> num_2;

    bool one_negative = false;

    if (num_1.at(0) == '-' && num_2.at(0) == '-') {

        num_1 = num_1.substr(1, num_1.length());
        num_2 = num_2.substr(1, num_2.length());

    } else if (num_1.at(0) == '-' || num_2.at(0) == '-') {

        one_negative = true;

        if (num_1.at(0) == '-') {

            num_1 = num_1.substr(1, num_1.length());

        } else if (num_2.at(0) == '-') {

            num_2 = num_2.substr(1, num_2.length());

        }
    }

    vector<string> total;

    total = multiply(num_2, num_1);

    if (one_negative) {
        cout << "-";
    }

    string final = "0";

    string copy;

    for (string i : total) {

        int _min = min(i.length(), final.length());
        int _max = max(i.length(), final.length());

        for (int times = 0; times < _max - _min; times++) {
            copy.append("0");
        }

        if (i.length() >= final.length()) {
            copy.append(final);
            final = copy;
        } else {
            copy.append(i);
            i = copy;
        }

        vector<int> _sum = add(i, final);

        string result;

        for (int a : _sum) {
            result.append(to_string(a));
        }
        final = result;

        copy = "";
    }
    cout << final << endl;
}