/*
Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //10 ms
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode * pre = start;
        ListNode* curr = head;
        while(curr)
        {   if (curr->next && (curr->val > curr->next->val))
            {
                while(pre->next && (pre->next->val <= curr->next->val))
                      pre = pre->next;
                ListNode* t = pre->next;
                pre->next = curr->next;
                curr->next = curr->next->next;
                pre->next->next = t;
                pre = start;
            }
            else curr = curr->next;
        }
        ListNode* header = start->next;
        delete start;
        return header;
    }
};
//100 ms
/*
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next ==NULL) return head;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp != NULL)
        {   if (prev->val > temp->val)
            {
                ListNode* curr = head;      ListNode* checkpoint = NULL;
                while(curr->val <= temp->val)
                {   checkpoint = curr;
                    curr = curr->next;
                }
                prev->next = temp->next;
                temp->next = curr;
                if (checkpoint != NULL)checkpoint->next = temp;
                else head = temp;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
*/
