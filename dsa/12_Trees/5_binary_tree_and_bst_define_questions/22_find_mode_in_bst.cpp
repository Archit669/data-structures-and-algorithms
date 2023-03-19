// approach-1 (bruteforce)

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
    void inorder(TreeNode* root, unordered_map<int,int> &m){
        if (!root) return ;
        inorder(root->left, m);
        m[root->val]++;
        inorder(root->right,m);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        inorder(root, m);

        int maxi = INT_MIN;
        for (auto &[ele, freq] : m){
            if (freq > maxi){
                maxi = freq;
            }
        }

        vector<int> ans;
        for (auto &[ele, freq] : m){
            if (freq ==  maxi){
                ans.push_back(ele);
            }
        }

        return ans;
    }
};