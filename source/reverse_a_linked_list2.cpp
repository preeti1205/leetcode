/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 
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
    void reverse(ListNode* head1, ListNode* head2) {
        ListNode* start = head1->next;
        ListNode* prev = head1;
        
        while(prev != head2) {
            ListNode* temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int counter = 1;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev1 = &dummy;
        ListNode* curr1 = head;
        while(counter < m) {
            prev1 = curr1;
            curr1 = curr1->next;
            counter++;
        }
        
       ListNode* prev2 = prev1;
       ListNode* curr2 = curr1;
       
       while(counter < n) {
            prev2 = curr2;
            curr2 = curr2->next;
            counter++;
        }
        ListNode* post2 = curr2->next;
        
        reverse(curr1, curr2);
        prev1->next = curr2;
        curr1->next = post2;
     
    return dummy.next;   
    }
};