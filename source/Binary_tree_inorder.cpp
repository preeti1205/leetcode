/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stacker;
        vector<int> result;
        while(!stacker.empty() || root)
        {
            while(root != NULL)
            {
                stacker.push(root);
                root = root->left;
             }
            root = stacker.top();
            stacker.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};

//recursive solution
/*
class Solution {
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return{};

        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);

        return result;
    }
};
*/
