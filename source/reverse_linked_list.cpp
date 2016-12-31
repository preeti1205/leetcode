/*
Reverse a singly linked list.
*/
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
        ListNode* tail = NULL;
        while(head) {
            ListNode* temp = head->next;
            head->next = tail;
            tail = head;
            head = temp;
        }

       return tail;
    }
};
