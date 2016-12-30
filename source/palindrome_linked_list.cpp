/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        vector<int> input;
        ListNode* temp = head;
        while(temp) {
            input.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* tail = reverse(head);

        int i = 0;
        int n = input.size();
        while(tail && (i <= n/2)) {
            if (tail->val != input[i]) return false;
            tail = tail->next;
            i++;
        }

        return true;
    }
};
