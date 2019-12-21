//
// Created by segni on 06/12/2019.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string beautiful_numbers() {
    int size, input;
    string result = "";
    cin >> size;
    int position[size];
    for (int i = 0; i < size; i++) {
        cin >> input;
        position[input - 1] = i;
    }

    int min = size + 1;
    int max = -1;
    for (int i = 0; i < size; i++) {
        if (min > position[i]) {
            min = position[i];
        }
        if (max < position[i]) {
            max = position[i];
        }
        if ((max - min) == i) {
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }
    return result;
}

int main() {
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << beautiful_numbers() << endl;
    }
}