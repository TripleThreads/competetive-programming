#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> add(const string &num_1, const string &num_2) {

    vector<int> total;

    int carry_on = 0;

    for (int index = num_1.length() - 1; index >= 0; index--) {

        int x = num_1.at(index) - 48; // 48 is ascii value of '0'
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

// if one the user input is negative we will subtract
vector<int> subs(const string &num_1, const string &num_2) {

    vector<int> total;

    int carry_on = 0;

    for (int index = num_1.length() - 1; index >= 0; index--) {

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
// check number and num_1 is less than num_2 swap for subtraction
bool check_swap(string &num_1, string &num_2, int negative_index) {

    for (int index = 0; index < num_1.length(); index++) {

        int x = num_1.at(index) - 48;
        int y = num_2.at(index) - 48;

        if (x > y) return negative_index == 1;

        if (x < y) {
            swap(num_1, num_2);

            return negative_index == 2;
        }

    }
    return false;
}

void sum() {

    string num_1, num_2, cpy;

    cin >> num_1 >> num_2;

    bool both_negative = false;
    bool single_negative = false;
    bool print_negative = false;
    int negative_index = 0;

    if (num_1.at(0) == '-' && num_2.at(0) == '-') {

        both_negative = true;

        num_1 = num_1.substr(1, num_1.length());
        num_2 = num_2.substr(1, num_2.length());

    } else if (num_1.at(0) == '-' || num_2.at(0) == '-') {

        single_negative = true;

        if (num_1.at(0) == '-') {

            num_1 = num_1.substr(1, num_1.length());
            negative_index = 1;

        } else if (num_2.at(0) == '-') {

            num_2 = num_2.substr(1, num_2.length());
            negative_index = 2;

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
    }

    vector<int> total;

    if (both_negative || !single_negative) {

        total = add(num_1, num_2);

    } else if (single_negative) {

        print_negative = check_swap(num_1, num_2, negative_index);

        total = subs(num_1, num_2);
    }

    if (both_negative || print_negative) {
        cout << "-";
    }

    for (int i : total) {
        cout << i;
    }
    cout << endl;
}