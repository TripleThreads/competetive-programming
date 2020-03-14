//
// Created by segni on 14/03/2020.
//
// https://www.hackerrank.com/challenges/2d-array/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int dir[7][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2}};
    int n = arr.size();
    int m = arr[0].size();
    int maxVal = INT_MIN;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int curVal = 0;
            for (auto d : dir) {
                curVal += arr[i + d[0]][j + d[1]];
            }
            maxVal = max(maxVal, curVal);
        }
    }
    return maxVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
