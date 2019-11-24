/**
 * @user segni
 * multiply large numbers this multiply reuse the add function from day 1
 * */

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

/**
 * @method multiply takes two numbers and multiply them returns in vector<string>
 * */
vector<string> multiply(const string &num_1, const string &num_2) {

    vector<string> total;
    map<int, string> mul_table;

    for (int index_num = num_1.length() - 1; index_num >= 0; index_num--) {
        int x = num_1.at(index_num) - 48;

        if (x == 0) continue;

        string temp;

        if (mul_table.find(x) == mul_table.end()) {

            int carry_on = 0;

            for (int index = num_2.length() - 1; index >= 0; index--) {

                int y = num_2.at(index) - 48;

                int z = x * y + carry_on;

                carry_on = z / 10;

                temp.push_back((z % 10) + '0');

                if (index == 0 && carry_on != 0) {
                    temp.push_back(carry_on + '0');
                }
            }
            reverse(temp.begin(), temp.end());
            mul_table[x] = temp;
        } else {
            temp = mul_table[x];
        }
        for (int a = 0; a < num_1.length() - index_num - 1; a++) {
            temp.append("0");
        }
        total.push_back(temp);
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

    ofstream output("mul output.txt");
    string sum = "0";

    for (const string &num: total) {
        sum = add(sum, num);
    }
    if (print_negative && sum.at(0) != '0') {
        cout << "-";
        output << "-";
    }
    output << sum << endl;
    output.close();
    cout << sum << endl;
}
