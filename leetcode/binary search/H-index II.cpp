//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int hIndex(vector<int>& citations) {

        int cite = 0, c_size = citations.size();

        int left = 0, right = c_size, mid = 0;

        while (left < right) {

            mid = (left + right) / 2;

            int rightSize = c_size - mid;

            // the minimum val between n - h and h
            int minVal = min(rightSize, citations[mid]);

            if (minVal > cite)
                cite = minVal;

            if (citations[mid] > cite)
                right = mid;

            else if (c_size - mid > cite)
                left = mid + 1;

            if (mid == 0 || cite >= rightSize && cite >= citations[mid - 1])
                return cite;

        }
        return cite;
    }
};