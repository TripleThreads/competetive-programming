//
// Created by segni on 21/12/2019.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        if (!head) return {};

        ListNode *node = new ListNode(head->val);
        vector<int> result, greater_nums;

        while (head->next) {
            head = head->next;
            ListNode *prev = node;
            node = new ListNode(head->val);
            node->next = prev;
        }

        int max = INT_MIN;
        while (node) {
            int val = node->val;
            node = node->next;

            greater_nums.push_back(val);

            if (val >= max) {
                result.push_back(0);
                max = val;
                continue;
            }
            for (int i = greater_nums.size() - 1; i >= 0; i--) {

                if (val < greater_nums[i]) {
                    result.push_back(greater_nums[i]);
                    break;
                }
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
