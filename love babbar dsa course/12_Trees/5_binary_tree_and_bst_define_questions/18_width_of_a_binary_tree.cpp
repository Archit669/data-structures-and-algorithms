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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long ans = 0;
        queue<pair<TreeNode*,unsigned long>> q;
        q.push({root, 0});

        while (!q.empty()){
            unsigned long l = q.front().second , r = q.back().second;
            ans = max(ans, r - l + 1);
            for (int k = q.size(); k > 0 ; k--){
                auto [node, idx] = q.front(); q.pop();
                if (node->left){
                    q.push({node->left, 2*idx + 1});
                }
                
                if (node->right){
                    q.push({node->right, 2*idx + 2});
                }
            }
        }

        return ans;
    }
};