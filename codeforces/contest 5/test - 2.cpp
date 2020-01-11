//
// Created by segni on 10/01/2020.
//

#include <iostream>
#include <climits>

using namespace std;

void yasserAdel() {
    int cakes;
    cin >> cakes;
    int input[cakes];
    long long int sum = 0;
    int pos = 0;
    for (int i = 0; i < cakes; i++) {
        cin >> input[i];
        sum += input[i];
        if (input[i] > 0)
            pos++;
    }
    if (pos == cakes) {
        cout << "YES" << endl;
        return;
    }
    if (input[0] <= 0 || input[cakes - 1] <= 0) {
        cout << "NO" << endl;
        return;
    }
    long long int curMax = 0, _max = INT_MIN;
    int c = 0;
    for (int num: input) {
        if (_max >= sum) {
            cout << "NO" <<endl;
            return;
        }
        if (num < num + curMax) {
            curMax = num + curMax;
            c++;
        }
        else {
            curMax = num;
            c = 1;
        }
        if (_max < curMax)
            _max = curMax;
    }
    if (sum > _max || c == cakes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        yasserAdel();
    }
    return 0;
}