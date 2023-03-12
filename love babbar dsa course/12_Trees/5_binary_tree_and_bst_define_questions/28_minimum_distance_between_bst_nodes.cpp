// approach -1 (dfs traversal)


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

// 1 -> min absolute difference
// 2 -> max value
// 3 -> min value

class Solution {  
    array<int,3> solve(TreeNode* root){
        if (root == nullptr){
            return {INT_MAX, -214748364, +214748364};
        }

        auto leftAns = solve(root->left);
        auto rightAns = solve(root->right);

        int min_abs_diff = min(leftAns[0], rightAns[0]);
        min_abs_diff = min(min_abs_diff , abs(root->val - leftAns[1]));
        min_abs_diff = min(min_abs_diff, abs(root->val - rightAns[2]));

        int max_value = max(max(leftAns[1], rightAns[1]), root->val);
        int min_value = min(min(leftAns[2], rightAns[2]), root->val);

        return {min_abs_diff, max_value, min_value};
    }
public:
    int minDiffInBST(TreeNode* root) {
        return solve(root)[0];
    }
};


// approach -2 (simple inorder traversal)
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

// 1 -> min absolute difference
// 2 -> max value
// 3 -> min value

class Solution { 
    void inorder(TreeNode* root, int &ans , int &prev){
        if (!root) return;
        inorder(root->left, ans, prev);
        ans = min(ans, abs(prev - root->val));
        prev = root->val;
        inorder(root->right, ans, prev);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -214748364;
        inorder(root, ans, prev);
        return ans;
    }
};