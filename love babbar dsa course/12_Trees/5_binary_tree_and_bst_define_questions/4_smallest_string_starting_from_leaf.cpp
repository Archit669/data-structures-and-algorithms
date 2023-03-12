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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return nullptr;
        string mini = "}";

        function<void(TreeNode* , string)> dfs=  [&](TreeNode* root, string curr){
            if (root == nullptr)
            {
                return;
            }

            curr += (root->val + 'a');

            if (!root->left && !root->right)
            {
                reverse(curr.begin(), curr.end());
                mini = min(mini, curr);
                return;
            }

            dfs(root->left, curr);
            dfs(root->right, curr);
        };

        dfs(root, "");

        return mini;
    }
};