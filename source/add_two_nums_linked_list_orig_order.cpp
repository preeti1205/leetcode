/*
You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* ReverseList(ListNode* l) {
        ListNode* prehead = l;
        ListNode* prev = NULL;

        while(prehead) {
            ListNode* temp = prehead->next;
            prehead->next = prev;
            prev = prehead;
            prehead = temp;
        }

        return prev;
    }

    ListNode* addTwoNumbersRev(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode pre(0);
        ListNode* ptr = &pre;
        while(l1 || l2 || carry) {
            if(l1) carry += l1->val;
            if(l2) carry += l2->val;
            ptr->next = new ListNode(carry%10);
            ptr = ptr->next;
            carry = carry/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return pre.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* prehead1 = l1;
        ListNode* prehead2 = l2;

        ListNode* prev1 = NULL;

        ListNode* prev2 = NULL;

        l1 = ReverseList(l1);
        l2 = ReverseList(l2);

    return ReverseList( addTwoNumbersRev(l1, l2));
    }
};
