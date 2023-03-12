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
    void inorder(TreeNode* root, int &ac){
        if (!root) return;
        inorder(root->right,ac);
        ac+= root->val;
        root->val = ac;
        inorder(root->left, ac);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int ac = 0;
        inorder(root, ac);
        return root;
    }
};