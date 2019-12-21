//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int size = A.size();
        vector<int> temp(size, 0);

        int j = 0;
        int k = 1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                temp[j] = A[i];
                j+=2;
            }
            if (A[i] % 2 == 1) {
                temp[k] = A[i];
                k+=2;
            }
        }
        return temp;
    }
};