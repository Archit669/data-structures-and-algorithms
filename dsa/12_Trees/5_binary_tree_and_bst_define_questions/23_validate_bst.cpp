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
    
    void inorder(TreeNode* root, long long &prev, bool &ans){
        if (!root) return;
        inorder(root->left, prev, ans);
        ans&= (prev < root->val);
        prev = root->val;
        inorder(root->right, prev, ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long prev = -2147483650;
        bool ans = true;
        inorder(root, prev, ans);
        return ans;
    }   
};