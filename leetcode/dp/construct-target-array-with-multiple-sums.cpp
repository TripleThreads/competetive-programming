class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) {
            return true;
        }
        int maxVal = 0;
        unordered_set<int> visited;
        for (int i : target) {
            if (i != 1 && visited.count(i))
                return false;
            
            visited.insert(i);
            if (i > maxVal) {
                maxVal = i;
            }
        }
        int count = visited.size();
        unsigned long long int a = 1, b = n, c = n + (n - 1);
        if (visited.count(a))
            count--;
        if (visited.count(b))
            count--;
        if (visited.count(c))
            count--;
        if (count == 0)
            return true;
        
        vector<int> vec;
        for (int i : visited) {
            vec.push_back(i);
        }
        
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] < c)
                continue;
            if ((vec[i] - n) % (n - 1) != 0) {
                return false;
            }
            unsigned long long int desired = (vec[i] - n) / (n - 1);
            if (!(visited.count(vec[i] - (n - 1)) && visited.count(vec[i] - 2 * (n - 1)))) {
                count--;
            }
            if (count == 0)
                return true;
        }
        return false;
    }
};
