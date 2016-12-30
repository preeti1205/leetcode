/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
the linked list should become 1 -> 2 -> 4 after calling your function

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;  //these two lines acn be replaced by a single line which will copy the whole struct
        node->next = node->next->next;// node to node->next  using this
        //: *node = *node->next link:https://discuss.leetcode.com/topic/18752/1-3-lines-c-java-python-c-c-javascript-ruby
        //this shortcut will however fail if node or node->next is NULL
    }
};
