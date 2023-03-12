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
    int sumNumbers(TreeNode* root) 
    {
        // edge case when tree is empty
        if (root == nullptr)
        {
            return 0;
        }

        // create a variable sum to store sum 
        int sum = 0;

        // create a queue and push root node with its curr value
        queue <pair<TreeNode*,int> > que {{{root, root->val}}};

        // bfs traversal
        while (!que.empty())
        {
            // take front node
            auto [node, curr] = que.front();
            
            // pop it from queue
            que.pop();

            // for leaf node
            if (!node->left && !node->right)
            {
                sum += curr;
            }

            // push left node with its curr value
            if (node->left)
            {
                que.push({node->left, curr*10 + node->left->val});
            }

            // push right node with its curr value
            if (node->right)
            {
                que.push({node->right, curr*10 + node->right->val});
            }
        }

        return sum;
    }
};