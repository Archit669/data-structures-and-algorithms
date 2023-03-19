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
public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<TreeNode *> q;

        q.push(root);

        int ans = root->val;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();

                q.pop();

                if (i == 0)
                {
                    ans = front->val;
                }

                if (front->left)
                {
                    q.push(front->left);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
            }
        }

        return ans;
    }
};