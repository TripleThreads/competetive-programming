//
// Created by segni on 21/11/2019.
//
#include <iostream>

using namespace std;

void calculator() {

    string user_input, num_1, num_2;

    int op = 0;

    cin >> user_input;

    int minus_op = user_input.find('-');
    int plus_op = user_input.find('+');
    int div_op = user_input.find('/');
    int multi_op = user_input.find('*');

    if (minus_op != -1 && minus_op != 0) {
        num_1 = user_input.substr(0, minus_op);
        num_2 = user_input.substr(minus_op + 1, user_input.length());
        op = 1;
    } else if (plus_op != -1) {
        num_1 = user_input.substr(0, minus_op);
        num_2 = user_input.substr(minus_op + 1, user_input.length());
        op = 2;
    } else if (div_op != -1) {
        num_1 = user_input.substr(0, minus_op);
        num_2 = user_input.substr(minus_op + 1, user_input.length());
        op = 3;
    } else if (multi_op != -1) {
        num_1 = user_input.substr(0, minus_op);
        num_2 = user_input.substr(minus_op + 1, user_input.length());
        op = 4;
    }


    bool both_negative = false;
    bool print_negative;

    int negative_index = 0;

    if (num_1.at(0) == '-' && num_2.at(0) == '-') {

        both_negative = true;

        num_1 = num_1.substr(1, num_1.length());
        num_2 = num_2.substr(1, num_2.length());

    } else if (num_1.at(0) == '-' || num_2.at(0) == '-') {

        if (num_1.at(0) == '-') {

            num_1 = num_1.substr(1, num_1.length());
            negative_index = 1;

        } else if (num_2.at(0) == '-') {

            num_2 = num_2.substr(1, num_2.length());
            negative_index = 2;
        }
    }

    print_negative = check_swap(num_1, num_2, negative_index);

    // since we want to 3 decimal points let's do that way
    int inc = divide(num_1, num_2);

    string decimal;

    for (int i = 0; i < 3; i++) {

        if (num_1.empty()) break;

        decimal.append(to_string(divide(num_1.append("0"), num_2)));
    }

    if (print_negative) {
        cout << "-";
    }
    cout << "result " << inc << "." << decimal << endl;

    cout << endl;
}