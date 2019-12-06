//
// Created by segni on 06/12/2019.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> split(const string &str) {

    string num;

    istringstream iss(str, istringstream::in);
    vector<int> int_array;

    while (iss >> num) {
        int_array.push_back(stoi(num));
    }
    return int_array;
}

string beautiful_numbers() {
    int size;
    string user_input;
    string result = "";
    cin >> size;
    std::getline(std::cin >> std::ws, user_input);

    vector<int> list = split(user_input);

    int position[size];

    for (int i = 0; i < size; i++) {
        position[list[i] - 1] = i;
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
    vector<string> results;
    for (int i = 0; i < size; i++) {
        results.push_back(beautiful_numbers());
    }
    for (string s: results) {
        cout << s << endl;
    }
}