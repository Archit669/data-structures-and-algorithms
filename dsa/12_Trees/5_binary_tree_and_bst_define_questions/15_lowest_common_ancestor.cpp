class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* leftAns = lowestCommonAncestor(root->left, p , q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p , q);

        if (leftAns && rightAns){
            return root;
        }

        if (!leftAns && rightAns){
            return rightAns;
        }

        if (leftAns && !rightAns){
            return leftAns;
        }

        return nullptr;
    }
};