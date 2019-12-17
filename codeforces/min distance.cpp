//
// Created by segni on 12/12/2019.
//

//
// Created by segni on 19/11/2019.
// Created by segni on 09/12/2019.
//
#include <iostream>
using namespace std;

int min_distance() {

    int input[3];
    int max = 0;
    int min = 0;
    for (int i = 0; i < 3; i++) {
        cin >> input[i];

        if (input[i] < input[min])
            min = i;
        if (input[i] > input[max])
            max = i;
    }
    int mid = 0;
    if (min == max) {
        mid = max;
        return 0;
    } else {
        for (int i = 0; i < 3; i++) {
            if (min != i && max != i)
                mid = i;
        }

        if (input[max] == input[mid] && input[max] > input[min] + 1) {
            input[mid]--;
            input[max]--;
        }
        else if (input[max] > input[mid])
            input[max]--;

        if (input[min] == input[mid] && input[min] < input[max]) {
            input[min]++;
            input[mid]++;
        }
        else if (input[min] < input[mid]) {
            input[min]++;
        }
        return abs(input[min] - input[max]) + abs(input[min] - input[mid]) + abs(input[mid] - input[max]);
    }
}
int main() {
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cout << min_distance() << endl;
    }
}