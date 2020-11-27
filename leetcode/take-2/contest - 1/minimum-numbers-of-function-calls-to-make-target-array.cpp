class Solution {
public:
    int minOperations(vector<int>& nums) {
        unsigned long long sum = 0;
        for (int i : nums) sum += i;
        int operation = 0;
        while (sum > 0) {
            sum = 0;
            for (int &i : nums) {
                if (i % 2) { // odd
                    operation++;
                    i--;
                }
                sum += i;
            }
            if (sum == 0) return operation;
            for (int &i : nums) { // even
                i /= 2;
            }
            operation++;
        }
        
        return operation;
    }
};
