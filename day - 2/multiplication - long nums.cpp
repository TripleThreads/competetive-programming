#include <iostream>
/**
 * @user segni
 * multiply large numbers this multiply reuse the add function from day 1
 * */

using namespace std;

/**
 * @method multiply takes two numbers and multiply them returns in vector<string>
 * */
vector<string> multiply(const string &num_1, const string &num_2) {

    vector<string> total;

    int carry_on = 0;

    for (int index_num = num_1.length() - 1; index_num >= 0; index_num--) {

        int x = num_1.at(index_num) - 48;

        vector<int> temp;

        for (int index = num_2.length() - 1; index >= 0; index--) {

            int y = num_2.at(index) - 48;

            int z = x * y + carry_on;

            if (index_num == 0) {

                temp.push_back(z);

            } else {
                temp.push_back(z % 10);
            }

            carry_on = z / 10;
        }
        string padding;

        for (long long int i = temp.size(); i >= 0; i--) {

            if (padding.empty() && temp[i] == 0) continue;

            padding.append(to_string(temp[i]));
        }
        for (int a = 0; a < num_1.length() - index_num - 1; a++) {
            padding.append("0");
        }
        total.insert(total.begin(), 1, padding);
    }
    return total;
}
/**
 * @method input takes input from user and polishes it
 * */
void mul_input(string num_1, string num_2) {

    bool print_negative = false;

    if (num_1.at(0) == '-') {

        print_negative = !print_negative;

        num_1 = num_1.substr(1, num_1.length());

    }
    if (num_2.at(0) == '-') {

        print_negative = !print_negative;

        num_2 = num_2.substr(1, num_2.length());
    }

    vector<string> total = multiply(num_2, num_1);

    string final = "0";

    for (string i : total) {

        check_swap(i, final, 0);

        vector<int> _sum = add(i, final);

        string result;

        for (int a : _sum) {
            result.append(to_string(a));
        }
        final = result;

    }
    if (print_negative && final != "0") {
        cout << "-";
    }
    cout << final << endl;
}