/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* pre = prehead;     //not needed for the better solution
        ListNode* prev = prehead;

        while(prev) {
            if(prev->next && prev->next->val == val) {
                ListNode* temp = prev->next;
                prev->next = prev->next->next;
                delete temp;                    //should take care of this
            }
            else prev = prev->next;
        }
        return prehead->next;

        /*
        while(head) {
            if(head->val == val ) {
                prev->next = head->next;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return pre->next;
        */
    }
};
