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
    ListNode* swapPairs(ListNode* head) {

        // first linked list size

        if (!head || !head->next) return head;

        int size = 0;

        ListNode *countHead = head;
        while (countHead) {
            size++;
            countHead = countHead->next;
        }
        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        while (size > 1) {

            ListNode *node =  new ListNode(head->val);

            head = head->next;
            ListNode *prev = node;
            node = new ListNode(head->val);
            node->next = prev;

            if (!newHead)
                newHead = node;

            if (tail)
                tail->next = node;

            tail = node->next;
            head = head->next;
            size -= 2;
        }
        if (size == 1) {
            tail->next = head;
        }
        return newHead;
    }
};