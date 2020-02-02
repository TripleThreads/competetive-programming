//
// Created by segni on 02/02/2020.
//

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        bool visited[friends.size()] = {false};
        visited[id] = true;
        vector<int> frnds;
        frnds.push_back(id);

        while (level--) {
            vector<int> newfrnds;
            for (int f : frnds) {
                for (int i : friends[f]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        newfrnds.push_back(i);
                    }
                }
            }
            frnds = newfrnds;
        }
        vector<string> result, temp;
        map<string, int> freq;
        for (int i : frnds)
            for (string s : watchedVideos[i])
                temp.push_back(s);

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pque;
        sort(temp.begin(), temp.end());
        for (string s: temp)
            freq[s]++;
        for (auto [k, v] : freq)
            pque.push({v, k});

        while (!pque.empty()) {
            auto [f, str] = pque.top();
            result.push_back(str);
            pque.pop();
        }
        return result;
    }
};