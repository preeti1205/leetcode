/*
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr) {
            if(prev->val == curr->val) {
                auto temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
