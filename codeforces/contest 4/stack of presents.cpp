//
// Created by segni on 28/12/2019.
//

#include <iostream>
#include <unordered_set>

using namespace std;
long long int stackOfPresents() {
    int n, m;
    long long int result = 0;

    cin >> n >> m ;
    unordered_set<int> set;

    int presents[n], send[m];
    for (int i = 0; i < n; i++)
        cin >> presents[i];

    for (int j = 0; j < m; j++)
        cin >> send[j];

    int n_i = 0, j = 0;

    for (int s: send) {
        if (set.find(s) != set.end()) {
            result++;
            set.erase(s);
            continue;
        }
        j = set.size();
        for (int i = n_i; i < n; i++) {
            if (presents[i] == s) {
                result += 2 * j + 1;
                n_i = i + 1;
                break;
            }
            set.insert(presents[i]);
            j++;
        }
    }
    return result;
}


int main () {
    int testCases;

    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cout << stackOfPresents() << endl;
    }
}