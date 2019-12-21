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
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return nullptr;

        ListNode *temp = head, *prev = head;
        int last_check = temp->val;
        temp = temp->next;

        while (temp) {
            if (last_check == temp->val) {
                prev->next = temp->next;
            }
            else {
                prev = temp;
                last_check = temp->val;
            }
            temp = temp->next;
        }

        return head;
    }
};