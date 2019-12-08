//
// Created by segni on 08/12/2019.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> split_string(const string &input) {
    string num;
    istringstream iss(input, istringstream::in);
    vector<int> res;
    while (iss >> num) {
        res.push_back(stoi(num));
    }

    return res;
}

string beautiful_regional_contest() {
    int size;
    string user_input, result;

    cin >> size;
    getline(cin >> ws, user_input);

    if (size < 10) return "0 0 0";

    vector<int> array = split_string(user_input);
    int mid = size / 2;
    vector<int> gold;
    vector<int> silver;
    vector<int> bronze;

    int gold_c = 0;
    int silver_c = 0;
    int bronze_c = 0;

    int mid_b = mid;
    while (array[mid_b] == array[mid - 1]) {
        mid--;
    }

    int max_gold_count = mid / 3;
    if (max_gold_count != 1) {
        max_gold_count--;
    }
    for (int i = 0; i < max_gold_count; i++) {
        if (array[i] > array[max_gold_count]) {
            gold_c++;
            gold.push_back(array[i]);
        }
    }
    for (int i = gold_c; i < (mid - max_gold_count); i++) {
        if (gold_c > 0 && array[i] < gold[gold_c - 1] && array[i] > array[mid - gold_c - 1]) {
            silver_c++;
            silver.push_back(array[i]);
        }
    }

    for (int i = gold_c + silver_c; i < mid; i++) {
        if (silver_c > 0 && silver[silver_c - 1] > array[i]) {
            bronze_c++;
            bronze.push_back(array[i]);
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
    vector<string> results;
    for (int i = 0; i < size; i++) {
        results.push_back(beautiful_regional_contest());
    }
    for (string s: results) {
        cout << s << endl;
    }
}
