//
// Created by segni on 10/03/2020.
//

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        long int sum = 0;
        int n = light.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long int num = i + 1, num2 = i + 2;
            sum += light[i];
            if (sum == num * num2 / 2) {
                count++;
            }
        }
        return count;
    }
};