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
    int distributeCoins(TreeNode* root) 
    {
        // variable that will store minimum no of moves
        int moves = 0;

        // function to find coins requirement for give or gain for given tree
        function<int(TreeNode*)> coinRequirement = [&](TreeNode* node)
        {
            // base case (tree is empty)
            if (node == nullptr)
            {
                return 0;
            }

            // find coin requirement for give or gain for left and right subtree
            int leftAns = coinRequirement(node->left);
            int rightAns = coinRequirement(node->right);

            // now update no of moves which is no of coin requirement for left subtree and right subtree 
            moves += abs(leftAns) + abs(rightAns);

            // return coin requirement for curr tree
            return node->val + leftAns + rightAns - 1;
        };

        coinRequirement(root);

        return moves;
    }
};