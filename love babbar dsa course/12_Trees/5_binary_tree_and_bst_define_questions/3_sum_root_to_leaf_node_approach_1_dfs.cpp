/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root, int curr = 0) 
    {
        // if node is null
        if (!root)
        {
            return 0;
        }

        // update curr
        curr = curr * 10 + root->val;

        // if node is leaf node then we have to return curr
        if (!root->left && !root->right)
        {
            return curr;
        }

        // return sum of left subtree and right subtree
        return sumNumbers(root->left, curr) + sumNumbers(root->right, curr);
    }
};