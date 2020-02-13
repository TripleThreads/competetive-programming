//
// Created by segni on 12/02/2020.
//

#include <iostream>
using namespace std;

void removeZeros() {
    string str;

    cin >> str;
    // trim zero
    int i;
    for (i = 0; i < str.length(); i++) {
        if (str.at(i) == '1')
            break;
    }
    str = str.substr(i);
    for (i = str.length() - 1; i >= 0; i--) {
        if (str.at(i) == '1')
            break;
    }
    str = str.substr(0, i);
    int count = 0;
    for (char c : str)
        if (c == '0')
            count++;
    cout << count << endl;
}

int main() {
    int len;
    cin >> len;

    for (int i = 0; i < len; i++) {
        removeZeros();
    }
}