//
// Created by segni on 20/11/2019.
//
#include <iostream>

using namespace std;

// this function is a utility function that helps us to check if the string is zero ex. returns true for 0000 and  false if 0001
bool is_zero(string &num_1) {
    for (char chr: num_1) {
        if (chr != '0')
            return false;
    }
    return true;
}

// this function returns increment size that is used to update quotient and appends 0's to denominator for fast division
unsigned long long int get_inc_by(string &num_1, string &num_2) {

    unsigned long long len_diff = num_1.length() - num_2.length();

    unsigned long long ten = 10;

    for (unsigned long long i = 0; i < len_diff - 1; i++) {
        num_2.append("0");
    }
    return len_diff - 1 > 0 ? pow(ten, len_diff - 1) : 1;
}

// we are not really gonna divide num_1 by num_2 rather we subtract num_2 from num_1 until it is less than num_2
unsigned long long int divide(string &num_1, string &num_2) {

    string total;

    string num2_original = num_2;

    unsigned long long int quotient = 0;

    check_swap(num_1, num_2);

    if (num_2 != num2_original) { // if tne numerator is less than denominator we will return 0
        swap(num_1, num_2);
        return quotient;
    }
    unsigned long long int inc_by = get_inc_by(num_1, num_2);

    string num2_large = num_2;

    while (true) {
        num_1 = subs(num_1, num_2);
        quotient += inc_by;
        if (num_1.empty() || is_zero(num_1)) {
            num_1 = "";
            break;
        }
        check_swap(num_1, num_2);

        // check if the numerator is less than denominator
        if (num2_large != num_2) {
            swap(num_1, num_2);
            num_2 = num2_original;

            check_swap(num_1, num_2);
            if (num2_original != num_2) {
                swap(num_1, num_2);
                break;
            }
            inc_by = get_inc_by(num_1, num_2);
            num2_large = num_2;
        }
    }
    return quotient;
}

void division_input(string num_1, string num_2) {

    bool print_negative = false;

    if (num_1.at(0) == '-') { // check if negative should be displayed or not

        print_negative = !print_negative;

        num_1 = num_1.substr(1, num_1.length());
    }
    if (num_2.at(0) == '-') {

        print_negative = !print_negative;

        num_2 = num_2.substr(1, num_2.length());
    }
    if (num_2 == "0") {
        cout << "invalid input " << endl;
        return;
    }
    unsigned long long int inc = divide(num_1, num_2);

    string decimal;

    // since we want to 3 decimal points let's do that way
    for (int i = 0; i < 3; i++) {

        if (num_1.empty() || num_1 == "0") break;

        decimal.append(to_string(divide(num_1.append("0"), num_2)));
    }
    if (print_negative) {
        cout << "-";
    }
    cout << inc << "." << (!decimal.empty() ? decimal : "0") << endl;
}