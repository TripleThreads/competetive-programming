//
// Created by segni on 12/02/2020.
//

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> count;

        for (string word : words) {
            string build;
            for (char c : word) {
                build += morse[c - 'a'];
            }
            count.insert(build);
        }
        return count.size();
    }
};