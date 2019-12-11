//
// Created by segni on 09/12/2019.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int size = 4, non_zero = 0;
    int count[size], position[size];

    for (int i = 0; i < size; i++) {
        cin >> count[i];
        position[i] = i;
        if (count[i] != 0) non_zero++;
    }

    if (count[0] > count[1] || count[3] > count[2] ||
        ((count[2] - 1 > count[1] + count[3]) && non_zero == 2) ||
        ((count[1] - 1 > count[0] + count[2]) && non_zero == 2)) {
        cout << "NO" << endl;
        return 0;
    }
    if (count[0] + count[2] <= count[1]) {
        swap(position[0], position[1]);
        swap(count[0], count[1]);
    }
    int index = 0, fast = 1, last_item = position[0] + 1;

    string beautiful_s;

    while ((index < size || fast < size) && (count[index] > 0 || count[fast] > 0)) {

        if (index < size - 1 && abs(last_item - position[index]) == 1 && count[index] > 0) {
            beautiful_s.append(to_string(position[index]) + " ");
            last_item = position[index];
            count[index]--;
        }
        if (fast < size && abs(last_item - position[fast]) == 1 && count[fast] > 0) {
            beautiful_s.append(to_string(position[fast]) + " ");
            last_item = position[fast];
            count[fast]--;
        }
        if (count[index] == 0) {
            index++;
        }
        if (index == fast || count[fast] == 0) {
            fast++;
        }
    }
    cout << "YES" << endl;
    cout << beautiful_s << endl;
}
