//
// Created by segni on 21/12/2019.
//

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        vector<int> result(T.size(), 0);

        stack<int> indexes;

        indexes.push(0);

        for (int i = 1; i < T.size(); i++) {

            while (!indexes.empty() && T[indexes.top()] < T[i]) {

                result[indexes.top()] = i - indexes.top();

                indexes.pop();
            }
            indexes.push(i);
        }

        return result;
    }
};