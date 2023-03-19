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
    // taverse all the nodes of the tree
    void inorder(TreeNode* root, int targetSum, int &count)
    {
            // base case
            if (!root)
            {
                return ;
            }

            // inorder of left subtree
            inorder(root->left, targetSum, count);

            // dfs of root node
            dfs(root, targetSum, count);

            // inorder of right subtree
            inorder(root->right, targetSum, count);
        }

        // function for dfs that will count all the paths that have targetSum
        void dfs(TreeNode* root, long long targetSum , int &count)
        {
            // empty tree
            if (root == nullptr)
            {
                return;
            }

            if (targetSum == root->val)
            {
                count++;
            }

            // path sum from leftSubtree
            dfs(root->left, targetSum - root->val, count);

            // path sum from rightSubtree
            dfs(root->right, targetSum - root->val, count);
        }

public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        int count = 0;

        inorder(root, targetSum, count);
        
        return count;
    }        
};