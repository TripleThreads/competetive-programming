//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        unordered_set<int> diff;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] > A[i])
                diff.insert(-1);
            else if (A[i - 1] == A[i])
                diff.insert(0);
            else
                diff.insert(1);
        }

        return !(diff.count(1) && diff.count(-1));
    }
};