//
// Created by segni on 21/12/2019.
//

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> lists;

        int x = 1, y = 0, left, right;

        for (int x = 1; x < z + 1; x++) {

            left = 1, right = z;

            for (int i = 0; i <= log2(z); i++) {

                y = (left + right) / 2;

                int res = customfunction.f(x, y);

                if (res == z) {
                    lists.push_back({x, y});
                    break;
                }
                else if (res < z) {
                    left = y + 1;
                }
                else {
                    right = y;
                }
            }

        }

        return lists;
    }
};