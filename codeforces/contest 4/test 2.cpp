//
// Created by segni on 27/12/2019.
//
#include <iostream>

using namespace std;

int skipForSanta() {
    int n, s;
    long long int sum = 0, temp = 0;
    cin >> n;
    cin >> s;
    int seconds[n];
    for (int i = 0; i < n; i++) {
        cin >> seconds[i];
        sum += seconds[i];
    }
    if (sum <= s) return 0;

    int skipped = -1, c = 0;

    for (int j = 0; j < n; j++) {
        if (skipped == -1) {
            if ((j < n - 1 && seconds[j] > seconds[j + 1]) || temp + seconds[j] > s) {
                skipped = j;
                continue;
            }
        }
        if (skipped != -1 && seconds[j] > seconds[skipped] && seconds[skipped] + temp <= s) {
            temp += seconds[skipped];
            skipped = j;
            c++;
        } else if (temp + seconds[j] <= s) {
            c++;
            temp += seconds[j];
        } else {
            break;
        }
    }
    return ++skipped;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
        cout << skipForSanta() << endl;

}
