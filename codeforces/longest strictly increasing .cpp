//
// Created by segni on 13/12/2019.
//

#include <iostream>

using namespace std;

void longest_strictly_increasing() {
    int size;
    cin >> size;
    int input[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    int maxCount = 1, count = 1, removed = 0;
    int pre = 0, post = 1;

    while (post < size) {
        if (input[pre] < input[post]) {
            if (post - pre > 1) {
                pre++;
            } else
                count++;
        } else if (!removed && count > 1) {
            removed = 1;
            if (post < size - 1 && input[pre] > input[post + 1]) {
                pre--;
                continue;
            }
        } else if (removed && input[pre] > input[post]) {
            removed = 0;
            if (maxCount < count)
                maxCount = count;
            count = 1;
            pre = post - 1;
        }
        pre++;
        post++;
    }
    if (maxCount < count)
        maxCount = count;
    cout << maxCount << endl;
}
int main() {
    longest_strictly_increasing();
}