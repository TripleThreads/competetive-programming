class Solution {
public:

    string reorganizeString(string S) {

        string result = "";

        int count[26] = {0}; // count of our alphabets in their index
        int maxCount = 0;
        int maxValue = 0;

        for (char c : S) {
            count[c - 97]++;
            if (count[c - 97] > maxCount) {
                maxCount = count[c - 97];
                maxValue = c;
            }
        }
        if (S.length() - maxCount <  maxCount) return "";
        vector<int> sub_list[maxCount];
        int index = 0;
        for (char c: S) {
            if (c == maxValue) continue;
            while (count[c - 97]-- > 0) {
                sub_list[(index++) % maxCount].push_back(c - 97);
            }
        }
        for (int i = 0; i < S.length(); i++) {
            result.push_back(maxValue);
            result.insert(result.end(), sub_list[i].begin(), sub_list[i].end());
        }
        return result;
    }
};