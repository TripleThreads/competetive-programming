//
// Created by segni on 23/12/2019.
//

class TopVotedCandidate {
public:
    vector<int> leading, times;

    unordered_map<int, int> count;

    int max = 0;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {

        this->times = times;

        for (int i = 0; i < times.size(); i++) {

            count[persons[i]]++;

            if (count[persons[i]] >= count[max]) {
                max = persons[i];
            }
            leading.push_back(max);
        }
    }

    int q(int t) {

        int t_size = times.size();
        int left = 0, right = t_size, mid = 0;

        while (left < right) {

            mid = (right + left) / 2;

            if (times[mid] <= t && (mid == t_size - 1 || times[mid + 1] > t))
                return leading[mid];

            else if (times[mid] > t)
                right = mid;

            else if (times[mid] < t)
                left = mid + 1;

        }

        return max;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */