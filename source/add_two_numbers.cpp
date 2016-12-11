/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 // 39ms code
void adder(int &value, bool &carry) {
    if(carry) value++;
    if (value > 9) {
        value = value%10;
        carry = true;
    }else carry = false;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = NULL;
        bool carry = false;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* worker = NULL;
        while(curr1 != NULL && curr2 != NULL){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(curr1 != NULL) worker = l1;
        else worker = l2;

        ListNode* result = worker;
        curr1 = l1;
        curr2 = l2;

        while(curr1 != NULL && curr2 != NULL) {
            int value = curr1->val + curr2->val ;
            adder(value, carry);
            worker->val = value;
            //cout<<curr1->val<<endl;
            curr1 = curr1->next;
            curr2 = curr2->next;
            prev = worker ;
            worker = worker->next;
        }

        while(worker != NULL && carry) {
            int value = worker->val;
            adder(value, carry);
            worker->val = value;
            prev = worker;
            worker = worker->next;
        }
        // ListNode last(1);    ---> don't use this.
        //It will create a local ListNode which will be destroyed as soon as this subroutine ends. Use new instead.

        if(carry) {
            assert(prev); //make sure prev is not null
            prev->next = new ListNode(1);
        }

       return result;

    }
};
