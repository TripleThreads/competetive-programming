//
// Created by segni on 04/02/2020.
//

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int s_ptr = 0, e_ptr = 0, cost = 0;
        while(e_ptr < s.length()){

            cost += abs(s[e_ptr] - t[e_ptr]);
            e_ptr++;

            if(cost > maxCost) {
                cost -= abs(s[s_ptr] - t[s_ptr]);
                s_ptr++;
            }
        }
        return e_ptr - s_ptr;
    }
};