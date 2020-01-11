//
// Created by segni on 10/01/2020.
//

#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int left = 0, right = 0;
    string input;
    cin >> input;
    for (char c: input) {
        if (c == 'L')
            left++;
        else
            right++;
    }
    cout << left + right + 1 << endl;
    return 0;
}