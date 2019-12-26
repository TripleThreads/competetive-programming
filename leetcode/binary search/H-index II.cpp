
//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    int hIndex(vector<int>& citations) {

        int h_index = 0, c_size = citations.size();

        int left = 0, right = c_size, mid = 0;

        while (left < right) {

            mid = (left + right) / 2;

            int rightSize = c_size - mid;

            // the minimum val between n - h and h
            int minVal = min(rightSize, citations[mid]);

            if (minVal > h_index)
                h_index = minVal;

            if (citations[mid] > h_index)
                right = mid;

            else if (rightSize > h_index)
                left = mid + 1;

            if (mid == 0 || h_index >= rightSize && h_index >= citations[mid - 1])
                return h_index;

        }
        return h_index;
    }
};
