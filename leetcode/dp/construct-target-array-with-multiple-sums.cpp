class Solution {
public:
   bool isPossible(vector<int>& target) {
        auto sum = accumulate(begin(target), end(target), (long long)0);
        priority_queue<int> que(begin(target), end(target));
        while (sum > 1 && que.top() > sum / 2) {
            auto cur = que.top(); 
            que.pop();
            auto prev = cur % (sum - cur);
            que.push(prev);
            sum -= cur - prev;
            cout << cur << " " << prev << " " << s << endl;
        }
        return sum <= target.size();
    }
};
