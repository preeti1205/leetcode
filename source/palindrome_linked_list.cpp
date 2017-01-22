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

 //O(1) super elegant Solution

 class Solution {
 public:
     bool isPalindrome(ListNode* head) {
         ListNode* fast = head;
         ListNode* slow = head;
         ListNode* rev = NULL;

         while(fast && fast->next) { //for even elements, fast becomes null and for odd, fast->next becomes null
             fast = fast->next->next;
             ListNode* temp = slow->next;
             slow->next = rev;
             rev = slow;
             slow = temp;
         }
         if(fast) slow = slow->next;  //if number of elements is odd, slow is at midpoint. Move it to the right

         while(rev && rev->val == slow->val) {
             rev = rev->next;
             slow = slow->next;
         }

         return !(rev);    //if null, then it is true else not
     }
 };

 /****************************************************************************/

 //O(1) extra space solution - not elegant
class Solution {
public:
   ListNode* reverseHalf(ListNode* head, int counter) {
       int count = counter/2;
       if(head == NULL) return head;
       ListNode* start = head;
       int i = 0;
       while( i < count ) {
           start = start->next;
           i++;
       }

       ListNode* prev = start;
       start = start->next;
       //cout<<start->val;

       prev->next = NULL;

       while(start) {
           ListNode* temp = start->next;
           start->next = prev;
           //cout<<prev->val<<"<--"<<start->val;
           prev = start;
           start = temp;
       }

       return prev;
   }

   bool isPalindrome(ListNode* head) {
       int counter = 0;
       ListNode* temp = head;
       while(temp) {
           temp = temp->next;
           counter++;
       }

       ListNode* tail = reverseHalf(head,counter);
       int i = 0;

       while(i < (counter/2) ) {
           if (tail->val != head->val) return false;
           tail = tail->next;
           head = head->next;
           i++;
       }

       return true;
   }
};

/*******************************************************************************/
//extra space O(n) - first try
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
