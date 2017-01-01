/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        ListNode p(0), *prehead = &p;
        prehead->next = l1;
        ListNode* prev = prehead;

        while (prehead->next && l2) {  //if you are using prehead, remember that prev is one before prehead not before prehead->next
            if(prehead->next->val > l2->val) {
                ListNode* temp = l2->next;
                l2->next = prehead->next;
                prehead->next = l2;
                prev = prev->next;
                prehead = prehead->next;
                l2 = temp;
            }
            else {
                prev = prehead;   //always keep in mind that prehead->next means the next value the ListNode is holding and not prehead itself. So if prehaed should point to a new value use prehead = prehead->next and not reference variable prehead->next = prehead->next->next
                prehead = prehead->next ;
            }
        }
        if(l2) prehead->next = l2;
       return p.next;
    }
};
