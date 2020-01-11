//
// Created by segni on 11/01/2020.
//

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
long long int lcm(long long int a,long long  int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long int num;
    cin >> num;
    vector<pair<long int, long int>> nums;
    long long int MAX = LONG_LONG_MAX;

    pair<long long int, long long int> p = make_pair(1, num);

    for (long long int i = 1; i <= sqrt(num); i++) {

        if (num % i == 0 && (num / i) % i != 0) {

            nums.emplace_back(num / i, i);

            if (lcm(num / i, i) == num) {
                if (MAX >  max(num / i, i)) {
                    MAX =  max(num / i, i);
                    p = make_pair(i, num / i);
                }
            }
        }
    }
    cout << min(p.first, p.second) << " " << max(p.first, p.second) <<  endl;
    return 0;
}