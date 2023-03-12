// approch-1 using vector and inorder traversal
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
    void inorder(TreeNode* root, vector<TreeNode *> &ans){
        if (!root) return ;
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode *> ans;
        inorder(root, ans);
        TreeNode* newRoot = new TreeNode(-1);
        TreeNode* temp = newRoot;

        for (auto &x : ans){
            x->left = x->right = nullptr;
            temp->right = x;
            temp = temp->right;
        }

        return newRoot->right;
    }
};

// approach -2 using recursion with return head and tail


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
    pair<TreeNode*, TreeNode*> solve(TreeNode* root){
        // for empty tree
        if (!root) return {nullptr, nullptr};

        // for leaf node
        if (!root->left && !root->right) return {root, root};

        // recursive call for ans from left tree
        auto [leftTreeHead, leftTreeTail] = solve(root->left);

        // recursive call for ans from right tree
        auto [rightTreeHead, rightTreeTail] = solve(root->right);

        // if we have both left tree and right tree
        if (leftTreeHead && rightTreeHead){
            leftTreeTail->right = root;
            root->right = rightTreeHead;
            // now disconnect left connection of root
            root->left = nullptr;
            return {leftTreeHead, rightTreeTail};
        }
        
        // if we have left tree but not right tree
        else if (leftTreeHead && !rightTreeHead){
             leftTreeTail->right = root;
             // now disconnect left connection of root
            root->left = nullptr;
             return {leftTreeHead, root};
        }
        
        // if we have right tree but not left tree
        else{
            root->right = rightTreeHead;
            // now disconnect left connection of root
            root->left = nullptr;
            return {root, rightTreeTail};
        }
    }


public:
    TreeNode* increasingBST(TreeNode* root) {
        auto [head, tail] = solve(root);
        return head;
    }
};
