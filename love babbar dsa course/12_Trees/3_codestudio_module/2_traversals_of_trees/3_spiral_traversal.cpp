#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    stack<BinaryTreeNode<int> *> s;

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front == NULL)
        {
            if (!q.empty())
                q.push(NULL);
            while (!s.empty())
            {
                ans.push_back(s.top()->data);
                s.pop();
            }
            level++;
        }
        else
        {
            if ((level & 1) == 0)
                ans.push_back(front->data);
            else
                s.push(front);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }

    return ans;
}



/*

// leetcode zigzag / spiral traversal
// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        bool dir = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL){
                if (!q.empty()) q.push(NULL);
                if (dir == 1){
                    reverse(temp.begin(), temp.end());
                }
                dir = !dir;
                ans.push_back(temp);
                temp = {};
            }else{
                temp.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

        }

        return ans;
    }
};

*/