//
// Created by segni on 08/12/2019.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string beautiful_regional_contest() {
    int size;
    string result;

    cin >> size;

    int input[size];
    int mid = size / 2;

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    if (size < 10 || input[0] == input[mid]) return "0 0 0";

    unsigned int gold, silver;

    int gold_c = 0, silver_c = 0, bronze_c = 0;

    int mid_b = mid;
    while (input[mid_b] == input[mid - 1]) {
        mid--;
    }
    // count gold
    int max_num = input[0];
    for (int i = 0; i < mid; i++) {
        if (input[i] == max_num) {
            gold_c++;
            gold = input[i];
        }
    }
    // count silver
    for (int i = gold_c; i < (mid - (gold_c + 1)); i++) {
        if (input[i] == input[mid]) return "0 0 0";
        if (gold_c > 0 && input[i] <= gold && input[i] > input[mid - gold_c - 1]) {
            silver_c++;
            silver = input[i];
        }
    }
    // count bronze
    for (int i = gold_c + silver_c; i < mid; i++) {
        if (input[i] == input[mid]) return "0 0 0";
        if (silver_c > 0 && input[i] <= silver) {
            bronze_c++;
        }
    }
    if (gold_c < silver_c && gold_c < bronze_c)
        result.append(to_string(gold_c) + " " + to_string(silver_c) + " " + to_string(bronze_c));
    else
        result = "0 0 0";
    return result;
}

int main() {
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << beautiful_regional_contest() << endl;
    }
}
