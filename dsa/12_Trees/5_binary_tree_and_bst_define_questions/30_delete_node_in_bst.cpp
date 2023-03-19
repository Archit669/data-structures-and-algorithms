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
    TreeNode* predessor(TreeNode* root){
        while (root->right){
            root = root->right;
        }
        
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (!root->left && !root->right && root->val == key) return nullptr;

        if (root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key){
            root->right = deleteNode(root->right, key);
        }

        else if (root->val == key){
            if (root->left){
                TreeNode* pred = predessor(root->left);
                swap(pred->val, root->val);
                root->left = deleteNode(root->left, key);
            }else{
                root = root->right;
            }
        }

        return root;
    }
};