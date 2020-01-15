//
// Created by segni on 15/01/2020.
//

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result;

        unordered_set<int> visited;

        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; j + i <= bound; j *= y) {
                visited.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        for (int i: visited)
            result.push_back(i);

        return result;
    }
};