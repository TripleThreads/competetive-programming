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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && !l2) return l1;
        if (!l1 && l2) return l2;
        if (!l1 && !l2) return nullptr;

        ListNode *newNode = new ListNode(0), *newHead = newNode;

        while (l1 || l2) {

            if (l1 && l2) {
                if (l1->val <= l2->val) {
                    newNode->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else {
                    newNode->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            else if (l1) {
                newNode->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                newNode->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            newNode = newNode->next;
        }

        return newHead->next;
    }
};