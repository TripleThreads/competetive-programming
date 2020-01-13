//
// Created by segni on 13/01/2020.
//
#include <iostream>
#include <vector>

using namespace std;

int shiftedArrSearch( const vector<int>& shiftArr, int num )
{
    // your code goes here
    int i;
    for (i = 1; i < shiftArr.size(); i++) {
        if (shiftArr[i] < shiftArr[i - 1])
            break;
    }
    int n = shiftArr.size();
    int shift = n - i;
    // binary search
    int left = 0, right = n, mid, shiftMid;

    while (left < right) {

        mid = (left + right) / 2;
        shiftMid = mid - shift;
        if (shiftMid < 0)
            shiftMid += n;

        if (shiftArr[shiftMid] > num)
            right = mid;

        else if (shiftArr[shiftMid] < num)
            left = mid + 1;
        else
            return shiftMid;
    }
    return (shiftMid + n - shift) % n;
}

int main() {
    vector<int> array = {5, 9, 12, 17, 1, 2, 4};
    cout << shiftedArrSearch(array, 4) << endl;
    return 0;
}
