/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up
all the values along the path equals the given sum.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        int curr_val = root->val;

        if (curr_val == sum) {
            if (root->left == NULL && root->right == NULL)
                return true;
        }
        bool left_val = hasPathSum(root->left, sum - curr_val);

        if (left_val == true) return left_val;
        else return hasPathSum(root->right, sum - curr_val);

    }
};
