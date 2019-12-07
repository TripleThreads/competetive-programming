//
// Created by segni on 06/12/2019.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> split(const string &str, int size) {

    string num;

    istringstream iss(str, istringstream::in);
    vector<int> position(size, 0);

    int i = 0;
    while (iss >> num) {
        position[stoi(num) - 1] = i;
        i++;
    }
    return position;
}

string beautiful_numbers() {
    int size;
    string user_input;
    string result = "";
    cin >> size;
    std::getline(std::cin >> std::ws, user_input);

    vector<int> position = split(user_input, size);

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