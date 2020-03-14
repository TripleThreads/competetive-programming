//
// Created by segni on 14/03/2020.
//
// https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long int count = 0;
    for (char c : s) {
        if (c == 'a') {
            count++;
        }
    }
    long long int quot = n / s.length();
    long long int total = quot * count;
    for (long long int i = 0; i < n - quot * s.length(); i++) {
        if (s.at(i) == 'a') {
            total++;
        }
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

