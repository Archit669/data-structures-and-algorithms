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
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root)
        {
            return {};
        }

        queue<TreeNode *> q;

        q.push(root);

        vector<int> ans;
        
        int maxi = INT_MIN;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();

                q.pop();

                maxi = max(maxi, front->val);

                if (front->left)
                {
                    q.push(front->left);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
            }

            ans.push_back(maxi);

            maxi = INT_MIN;
        }

        return ans;
    }
};