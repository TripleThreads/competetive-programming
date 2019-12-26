//
// Created by segni on 25/12/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

long int price_of_one() {
    long int n, p, k = 2;

    cin >> n;
    cin >> p;
    cin >> k;

    long int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    if (p < nums[0]) return 0;

    long int inc = 0;

    int first = true;
    for (int i = n - 1; i >= 0 && p > 0; i--) {
        long int sum = 0;
        for (int k = 0; k < i; i++) {
            sum += nums[k];
        }
        if (nums[i] <= p && first && (nums[i - 1] < nums[i] || i <=2 || sum <= p)) {
            inc += 2;
            first = false;
            i--;
            p = p - nums[i];
        }
        else if (nums[i] <= p && !first) {
            inc++;
            p = p - nums[i];
        }
    }
    return inc;
}

int main() {
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << price_of_one() << endl;
    }

}