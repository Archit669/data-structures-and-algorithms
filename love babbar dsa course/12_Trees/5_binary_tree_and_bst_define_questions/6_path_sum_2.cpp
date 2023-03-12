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
    // vector to store all paths
    vector<vector<int>> paths;

    // path sum function
    bool solve(TreeNode* root, int targetSum, vector<int> &path)
    {
        // tree is empty
        if (!root)
        {
            return false;
        }

        // leaf node with given target
        if (!root->left && !root->right && root->val == targetSum)
        {
            path.push_back(root->val);

            paths.push_back(path);

            path.pop_back();

            return true;
        }

        // recursive step
        path.push_back(root->val);

        bool leftAns = solve(root->left, targetSum - root->val, path);

        bool rightAns = solve(root->right, targetSum- root->val, path);

        path.pop_back();

        return leftAns || rightAns;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> path;

        solve(root, targetSum, path);

        return paths;
    }
};