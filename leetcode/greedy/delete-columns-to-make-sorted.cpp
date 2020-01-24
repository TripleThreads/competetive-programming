//
// Created by segni on 24/01/2020.
//

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0, size = A.size();

        for (int i = 0; i < A[0].length(); i++) {
            char c = '0';
            for (string str: A) {
                if (str.at(i) < c) {
                    result++;
                    break;
                }
                c = str.at(i);
            }
        }
        return result;
    }
};