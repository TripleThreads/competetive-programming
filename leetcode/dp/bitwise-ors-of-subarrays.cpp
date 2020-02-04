//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> bits;
        int n = A.size();
        vector<set<int>> matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].insert(A[i]);
            bits.insert(A[i]);

            if (i > 0) {
                for (auto a : matrix[i - 1]) {
                    int res = a | A[i];
                    bits.insert(res);
                    matrix[i].insert(res);
                }
            }
        }
        return bits.size();
    }
};