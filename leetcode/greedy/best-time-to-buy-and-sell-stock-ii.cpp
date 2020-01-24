//
// Created by segni on 23/01/2020.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0)
            return 0;

        int profit = 0, n = prices.size();
        int _max = 0, ptr_min = 0, ptr_max = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                ptr_max++;

            else if (prices[ptr_max] > prices[ptr_min]) {
                profit += prices[ptr_max] - prices[ptr_min];
                ptr_min = i;
                ptr_max = i;
            }
            else {
                ptr_max++;
                ptr_min++;
            }
        }
        if (prices[ptr_min] < prices[ptr_max] && ptr_max == n - 1)
            profit += prices[ptr_max] - prices[ptr_min];

        return profit;
    }
};