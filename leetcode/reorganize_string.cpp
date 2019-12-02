class Solution {
public:
    // check if the count is empty that means all the characters are inserted
    bool is_empty(int array[]) {
        for (int i = 0; i < 26; i++) {
            if (array[i] != 0)
                return false;
        }
        return true;
    }
    // find the most repeated letter without last inserted one
    int _max(int array[], int ex_ix) {

        int max = ex_ix;

        for (int a = 0; a < 26; a++) {

            if (a == ex_ix) continue;

            if (max == ex_ix || array[a] > array[max]) {
                max = a;
            }

        }
        return max;
    }

    string reorganizeString(string S) {

        string result = "";

        int count[26] = {0}; // count of our alphabets in their index

        for (char c : S) {
            count[c - 97]++;
        }
        // if the character is already inserted to final we will exclude it from next max repeated
        int exclude_ix = 26;

        for (int i = 0; i < S.length(); i++) {

            int max = _max(count, exclude_ix);

            if (count[max] == 0) break;

            result.push_back(97 + max);

            count[max]--;

            exclude_ix = max;
        }

        if (is_empty(count)) {
            return result;
        }

        return "";
    }
};