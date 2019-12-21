//
// Created by segni on 21/12/2019.
//

Copy
#include <iostream>
#include <set>

using namespace std;

void all_substrings() {
    int length, keysLength;
    string userInput;

    cin >> length;
    cin >> keysLength;
    cin >> userInput;

    set<char> av_chars;
    char temp;
    for (int i = 0; i < keysLength; i++) {
        cin >> temp;
        av_chars.insert(temp);
    }
    unsigned long long int sum = 0, count = 0;
    for (char c : userInput) {
        if (av_chars.find(c) != av_chars.end()) {
            count++;
        }
        else {
            sum += (count * (count + 1)) / 2;
            count = 0;
        }
    }
    sum += (count * (count + 1)) / 2;
    cout << sum << endl;
}

int main () {
    all_substrings();
}