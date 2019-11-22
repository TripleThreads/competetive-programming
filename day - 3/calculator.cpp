//
// Created by segni on 21/11/2019.
//
#include <iostream>

using namespace std;

void calculator() {

    string user_input, num_1, num_2;
    cout << "Please enter your operation > ";

    cin >> user_input;

    int minus_op = user_input.find_last_of('-');
    int plus_op = user_input.find('+');
    int div_op = user_input.find('/');
    int multi_op = user_input.find('*');

    if (multi_op != -1) {
        num_1 = user_input.substr(0, multi_op);
        num_2 = user_input.substr(multi_op + 1, user_input.length());

        mul_input(num_1, num_2);
    } else if (div_op != -1) {
        num_1 = user_input.substr(0, div_op);
        num_2 = user_input.substr(div_op + 1, user_input.length());
        division_input(num_1, num_2);

    } else if (plus_op != -1) {
        num_1 = user_input.substr(0, plus_op);
        num_2 = user_input.substr(plus_op + 1, user_input.length());
        sum_input(num_1, num_2);

    } else if (minus_op != -1 && minus_op != 0) {
        num_1 = user_input.substr(0, minus_op);
        num_2 = user_input.substr(minus_op, user_input.length());

        // there might be x--y i.e. x+y so we handle that here
        if (user_input.at(minus_op - 1) == '-') {
            num_1 = num_1.substr(0, num_1.length() - 1);
            num_2 = num_2.substr(1, num_2.length());
        }
        sum_input(num_1, num_2);
    }
}