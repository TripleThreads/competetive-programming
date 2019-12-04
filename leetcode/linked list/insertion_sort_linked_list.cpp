//
// Created by segni on 04/12/2019.
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
    ListNode* insertionSortList(ListNode* head) {

        if (!head || !head->next) return head;

        int i = 1;

        ListNode *head_backup = head, *prev_head = head;

        head = head->next;

        while (head) {

            ListNode *temp = head_backup, *prevTemp = head_backup;

            int j = 0;

            while(j < i && head->val > temp->val) {
                prevTemp = temp;
                temp = temp->next;
                j++;
            }

            if (i == j && head->val >= temp->val) {
                prev_head = head;
                head = head->next;
                i++;
                continue;
            }

            ListNode *new_head = new ListNode(head->val);

            new_head->next = temp;

            if (j == 0) {
                head_backup = new_head;
            } else {
                prevTemp->next = new_head;
            }

            head = head->next;

            prev_head->next = head;

            i++;
        }

        return head_backup;
    }
};