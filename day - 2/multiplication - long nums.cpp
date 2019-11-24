/**
 * @user segni
 * multiply large numbers this multiply reuse the add function from day 1
 * */

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

vector<int> add_mul(const vector<int>& num_1, const string &num_2) {

    int max_iter = max(num_1.size(), num_2.length());

    int num_1_index = num_1.size() - 1;

    int num_2_index = num_2.length() - 1;

    vector<int> total;

    int carry_on = 0;

    for (int index = max_iter - 1; index >= 0; index--) {

        int x = (num_1_index >= 0) ? num_1[num_1_index--] : 0;

        int y = (num_2_index >= 0) ? num_2.at(num_2_index--) - 48 : 0;

        int z = x + y + carry_on;

        if (index == 0) {

            total.push_back(z);

        } else {
            total.push_back(z % 10);
        }

        carry_on = z / 10;

    }
    reverse(total.begin(), total.end());

    return total;
}

/**
 * @method multiply takes two numbers and multiply them returns in vector<string>
 * */
vector<string> multiply(const string &num_1, const string &num_2) {

    vector<string> total;
    map<int, string> mul_table;
    int carry_on = 0;

    for (int index_num = num_1.length() - 1; index_num >= 0; index_num--) {
        int x = num_1.at(index_num) - 48;

        if (x == 0) continue;

        string padding;

        if (mul_table.find(x) == mul_table.end()) {

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
            for (long long int i = temp.size(); i >= 0; i--) {

                if (padding.empty() && temp[i] == 0) continue;

                padding.append(to_string(temp[i]));
            }
            mul_table[x] = padding;
        } else {
            padding = mul_table[x];
        }
        for (int a = 0; a < num_1.length() - index_num - 1; a++) {
            padding.append("0");
        }
        total.push_back(padding);
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

    vector<int> final = {0};

    for (const string &num: total) {

        final = add_mul(final, num);

    }
    if (print_negative && final.at(0) != 0) {
        cout << "-";
    }

    ofstream output("mul output.txt");

    for (int f: final) {
        output << f;
        cout << f;
    }
    output << endl;
    output.close();
    cout << endl;
}