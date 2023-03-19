class Solution {
    void solve(TreeNode* root, vector<string>& ans, string path){
        if (!root) return ;
        if (!root->left && !root->right){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        } 

        solve(root->left, ans, path+to_string(root->val) + "->");
        solve(root->right, ans, path+to_string(root->val) + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, ans, "");
        return ans;
    }
};