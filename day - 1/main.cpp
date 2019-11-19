#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> add(const string &num_1, const string &num_2, int _max) {

    vector<int> total;

    int carry_on = 0;

    for (int index = _max - 1; index >= 0; index--) {

        int x = num_1.at(index) - 48;
        int y = num_2.at(index) - 48;

        int z = x + y + carry_on;

        if (index == 0) {

            total.insert(total.begin(), 1, z);

        } else {
            total.insert(total.begin(), 1, z % 10);
        }

        carry_on = z / 10;

    }
    return total;
}

vector<int> subs(const string &num_1, const string &num_2, int _max) {

    vector<int> total;

    int carry_on = 0;

    for (int index = _max - 1; index >= 0; index--) {

        int x = num_1.at(index) - 48;
        int y = num_2.at(index) - 48;

        x -= carry_on;

        if (x < y) {

            x += 10;

            carry_on = 1;

        } else {

            carry_on = 0;

        }

        int z = x - y;

        if (index == 0 && z == 0) {

            continue;

        } else {
            total.insert(total.begin(), 1, z);
        }

    }
    return total;
}

void sum() {

    string num_1;
    string num_2;
    string cpy;


    cin >> num_1 >> num_2;

    bool both_negative = false;
    bool one_negative = false;
    bool print_negative = false;

    if (num_1.at(0) == '-' && num_2.at(0) == '-') {

        both_negative = true;

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


    int _min = min(num_1.length(), num_2.length());
    int _max = max(num_1.length(), num_2.length());

    for (int times = 0; times < _max - _min; times++) {
        cpy.append("0");
    }

    if (num_1.length() >= num_2.length()) {
        cpy.append(num_2);
        num_2 = cpy;
    } else {
        cpy.append(num_1);
        num_1 = cpy;
        swap(num_1, num_2);
        print_negative = true;
    }

    vector<int> total;

    if (both_negative || !one_negative) {
        total = add(num_1, num_2, _max);
    } else if (one_negative) {
        if (num_1.length() == num_2.length()) {
            if (num_1.at(0) < num_2.at(0)) {
                swap(num_1, num_2);
                print_negative = true;
            }
        }

        total = subs(num_1, num_2, _max);
    }

    if (both_negative || one_negative) {
        cout << "-";
    }

    for (int i : total) {
        cout << i;
    }
    cout << endl;
}

int main() {
    sum();
    return 0;
}