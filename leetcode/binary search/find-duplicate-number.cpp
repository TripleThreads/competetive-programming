//
// Created by segni on 23/12/2019.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int left = 1, right = nums.size() - 1;

        while(left < right){

            int mid = left + (right - left) / 2;
            int count = 0;

            for(int num: nums){
                if(num <= mid) count++;
            }

            if(count > mid)
                right = mid;

            else
                left = mid + 1;
        }

        return right;
    }
};