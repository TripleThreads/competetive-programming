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
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode *first = new ListNode(head->val);

        while (head->next) {
            head = head->next;
            ListNode *prev = first;
            first = new ListNode(head->val);
            first->next = prev;
        }

        return first;
    }
};