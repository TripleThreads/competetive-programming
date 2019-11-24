#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * @method add takes two string numbers and add them returns vector<int>
 * */
string add(const string &num_1, const string &num_2) {

    int max_iter = max(num_1.size(), num_2.length());

    int num_1_index = num_1.size() - 1;

    int num_2_index = num_2.length() - 1;

    string total;

    int carry_on = 0;

    for (int index = max_iter - 1; index >= 0; index--) {

        int x = (num_1_index >= 0) ? num_1.at(num_1_index--) - 48 : 0;
        int y = (num_2_index >= 0) ? num_2.at(num_2_index--) - 48 : 0;

        int z = x + y + carry_on;
        carry_on = z / 10;

        total.push_back(z % 10 + '0');

        if (index == 0 && carry_on != 0)
            total.push_back(carry_on + '0');

    }
    reverse(total.begin(), total.end());

    return total;
}

// if one the user input is negative we will subtract
string subs(const string &num_1, const string &num_2) {

    string total;

    int num_2_index = num_2.length() - 1;

    int carry_on = 0;

    for (int index = num_1.length() - 1; index >= 0; index--) {

        int x = num_1.at(index) - 48;
        int y = (num_2_index >= 0) ? num_2.at(num_2_index--) - 48 : 0;

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
            total.push_back(z + '0');
        }

    }
    reverse(total.begin(), total.end());

    return total;
}

// check number and num_1 is less than num_2 swap for subtraction
bool check_swap(string &num_1, string &num_2, int negative_index = 0) {

    if (num_1.length() > num_2.length()) return negative_index == 1;

    if (num_2.length() > num_1.length()) {
        swap(num_1, num_2);
        return negative_index == 2;
    }


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

void sum_input(string num_1, string num_2) {

    bool both_negative = false;
    bool single_negative = false;
    bool print_negative;
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
    string total;

    print_negative = check_swap(num_1, num_2, negative_index);

    if (both_negative || !single_negative) {

        total = add(num_1, num_2);

    } else if (single_negative) {

        total = subs(num_1, num_2);

    }
    if (both_negative || print_negative) {
        cout << "-";
    }
    cout << total << endl;

    if (total.empty())
        cout << 0;
}