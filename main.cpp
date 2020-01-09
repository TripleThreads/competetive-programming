#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, j;
    cin >> n;
    vector<vector<int>> inputs;
    unsigned long long int count = 0;
    int xx = 0;
    for (int i = 0; i < n; i++) {
        cin >> j;
        vector<int> temp(j);
        bool exists = false;
        int m = INT_MAX;
        for (int x = 0; x < j; x++) {
            cin >> temp[x];
            if (temp[x] < m)
                m = temp[x];
            else if (temp[x] > m)
                exists = true;
        }
        if (exists) {
            xx++;
            count += n;
        }
        else
            inputs.push_back(temp);
    }
    count += inputs.size() * xx;

    for (auto const &first: inputs) {
        for (auto const &sec: inputs) {
            if (first[first.size() - 1] < sec[0])
                count++;
        }
    }
    cout << count << endl;
    return 0;
}