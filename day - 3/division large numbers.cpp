//
// Created by segni on 20/11/2019.
//

#include <iostream>
#include <vector>

using namespace std;

// we are not really gonna divide num_1 by num_2 rather we subtract num_2 from num_1 until it is less than num_2
long int divide(string &num_1, string &num_2) {

    vector<int> total;
    string result, temp = num_2;

    long int inc = 0;

    check_swap(num_1, num_2);

    if (num_2 != temp) { // if tne numerator is less than denominator we will return 0
        swap(num_1, num_2);
        return inc;
    }

    do {
        total = subs(num_1, num_2);

        for (int a : total) {
            result.append(to_string(a));
        }
        num_1 = result;
        total.clear();
        result = "";
        inc++;

        if (num_1.empty()) break;

        check_swap(num_1, num_2);

        // check if the numerator is less than denominator
        if (temp != num_2) {
            swap(num_1, num_2);
            break;
        }
    } while (true);

    return inc;
}

void division() {

    string num_1, num_2;

    cin >> num_1 >> num_2;

    bool print_negative = false;


    if (num_1.at(0) == '-') {

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
    // since we want to 3 decimal points let's do that way
    long int inc = divide(num_1, num_2);

    string decimal;

    for (int i = 0; i < 3; i++) {

        if (num_1.empty() || num_1 == "0") break;

        decimal.append(to_string(divide(num_1.append("0"), num_2)));
    }

    if (print_negative) {
        cout << "-";
    }
    cout << inc << "." << (!decimal.empty() ? decimal : "0") << endl;

    cout << endl;
}