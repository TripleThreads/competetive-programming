#include <iostream>

using namespace std;

long int temp_unavailable() {
    long int nums[4];

    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }
    long int a = min(nums[1], nums[0]), b = max(nums[1], nums[0]);
    long int c = nums[2], r = nums[3], ans, t = 0;

    if (a == b && b == c) return 0;

    if (a <= c && c <= b)
        t = min(b - c, r) + min(c - a, r);

    else if (b <= c)
        t = r - (c - b);

    else if (c <= a)
        t = r - (a - c);

    if (t < 0 && !(a <= c && c <= b))
        t = 0;

    ans = abs(b - a) - t;
    return (ans < 0) ? 0 : ans;
}

int main() {
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << temp_unavailable() << endl;
    }
}