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
    void solve(TreeNode* root,  map<int, map<int,multiset<int> >> &m, int vertical, int lvl){
        if (root == nullptr){
            return;
        }

        m[vertical][lvl].insert(root->val);
        solve(root->left, m, vertical-1, lvl+1);
        solve(root->right, m , vertical + 1, lvl+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int,multiset<int>>> m;
        solve(root, m , 0, 0);
        

        for (auto [key,lvlMap] : m){
            vector<int> temp;
            for (auto &[k, arr] : lvlMap){
                for (auto &ele : arr){
                    temp.push_back(ele);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};