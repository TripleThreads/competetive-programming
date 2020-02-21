//
// Created by segni on 21/02/2020.
//

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> pushedStack, poppedStack;
        int n = popped.size();
        for (int i = n - 1; i >= 0; i--) {
            poppedStack.push(popped[i]);
        }
        for (int i : pushed) {
            pushedStack.push(i);
            while (poppedStack.size() > 0 && pushedStack.size() > 0 && poppedStack.top() == pushedStack.top()) {
                poppedStack.pop();
                pushedStack.pop();
            }
        }
        return pushedStack.size() == 0 && pushedStack.size() == poppedStack.size();
    }
};