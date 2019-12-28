//
// Created by segni on 27/12/2019.
//

#include <iostream>

using namespace std;

string new_year() {
    int count[3], maxValue = 0, sum = 0;

    for (int i = 0; i < 3; i++) {
        cin >> count[i];
        if (count[i] > maxValue) {
            maxValue = count[i];
        }
        sum += count[i];
    }
    if (sum - maxValue < maxValue - 1)
        return "No";
    return "Yes";
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
        cout << new_year() << endl;

}