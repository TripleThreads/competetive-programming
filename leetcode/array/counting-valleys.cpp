//
// Created by segni on 14/03/2020.
//
// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count = 0;
    int curEl = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'U') {
            curEl++;
            if (curEl == 0) {
                count++;
            }
        }
        else if (s.at(i) == 'D') {
            curEl--;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

