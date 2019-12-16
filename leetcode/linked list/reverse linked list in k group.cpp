//
// Created by segni on 03/12/2019.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int size = 0;
        ListNode *temp = head;
        
        while (temp) {
            temp = temp->next;
            size++;
        }
        if (size == 0 || size < k || k <= 1) return head;
        
        ListNode *newHead = nullptr, *prevTail = nullptr;
        ListNode *node = head, *tail = head;
        
        int j = 0;
        
        while (size / k >= 1) {
            
            for (int i = 0; i < k - 1; i++) {
                head = head->next;
                ListNode *prev = node;
                node = new ListNode(head->val);
                node->next = prev;
            }

            tail->next = head->next;
            
            if (prevTail != nullptr) 
                prevTail->next = node;
            
            if (newHead == nullptr)
                newHead = node;
            
            size -= k;
            prevTail = tail;
            head = head->next;
            tail = head;
            node = tail;
        }
        return newHead;
    }
};
