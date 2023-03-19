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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // empty tree
        if (!root) return nullptr;
        
        // root value is less than low then right trim bst should be ans
        if (root->val < low){
            return trimBST(root->right, low, high);
        }

        // root value is greater than high then left trim bst should be ans
        if (root->val > high){
            return trimBST(root->left, low, high);
        }

        // root value is in between left and right

        // trim leftsubtree bst and connect it to left of root
        root->left = trimBST(root->left, low, high);

        // trim rightsubtree bst and connect it to right of root
        root->right = trimBST(root->right, low, high);

        // return root;
        return root;
    }
};