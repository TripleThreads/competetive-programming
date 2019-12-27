//
// Created by segni on 27/12/2019.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *res = new ListNode(0), *head = res;

        priority_queue<int, vector<int>, greater<int>> que;
        for (ListNode *node: lists)
            while (node) {
                que.push(node->val);
                node = node->next;
            }

        while (!que.empty()) {
            res->next = new ListNode(que.top());
            res = res->next;
            que.pop();
        }
        return head->next;
    }
};