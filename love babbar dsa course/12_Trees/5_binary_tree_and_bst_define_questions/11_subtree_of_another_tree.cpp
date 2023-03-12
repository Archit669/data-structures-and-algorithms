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
class Solution
{
    string preorder(TreeNode *root)
    {
        if (!root)
        {
            return ",#";
        }

        string ans;

        ans += "," + to_string(root->val);

        ans += preorder(root->left);

        ans += preorder(root->right);

        return ans;
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string mainTree = preorder(root);

        string subTree = preorder(subRoot);

        return mainTree.find(subTree) != string::npos;
    }
};