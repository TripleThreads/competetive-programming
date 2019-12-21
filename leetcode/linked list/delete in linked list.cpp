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
    void deleteNode(ListNode* node) {

        ListNode *prev = new ListNode(node->val);

        while (node->next) {

            node->val = node->next->val;
            prev = node;
            node = node->next;
        }

        prev->next = nullptr;
    }
};