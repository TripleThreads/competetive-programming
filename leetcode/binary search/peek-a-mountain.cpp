//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int left = 0, right = A.size() - 1;

        while (left < right) {

            int mid = (left + right) / 2;

            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
                return mid;

            else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return -1;
    }
};