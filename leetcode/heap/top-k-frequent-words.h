//
// Created by segni on 27/12/2019.
//

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> result, temp;

        priority_queue<pair<int, string>> que;

        unordered_map<string, int> dict;

        for (string word: words)
            dict[word]++;

        for (auto const &[key, value] : dict)
            que.push(make_pair(value, key));

        int last = que.top().first;

        for (int i = 0; i < k || !que.empty() && que.top().first == last; i++) {
            auto item = que.top();
            if (last == item.first)
                temp.push_back(item.second);

            else {
                sort(temp.begin(), temp.end());
                result.insert(result.end(), temp.begin(), temp.end());
                temp.clear();
                temp.push_back(item.second);
                last = item.first;
            }
            que.pop();
        }
        if (!temp.empty()) {
            sort(temp.begin(), temp.end());
            result.insert(result.end(), temp.begin(), temp.end());
        }
        while (result.size() > k)
            result.pop_back();

        return result;
    }
};