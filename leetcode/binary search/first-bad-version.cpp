//
// Created by segni on 21/12/2019.
//

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        unsigned long int mid = n / 2;
        unsigned long int prev = 0;

        while (true) {

            if (mid > 0 && isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            }

            if (!isBadVersion(mid)) {
                prev = mid;
                mid = (mid + n + 1) / 2;
            }
            else {

                mid = (mid + prev) / 2;
            }
        }
    }
};