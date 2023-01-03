#include <bits/stdc++.h>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> reverseLevelOrder(TreeNode<int> *root){
    vector<int> ans;
    queue<TreeNode<int>*> q;
    if (root) q.push(root);
    while (!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        ans.push_back(front->val);
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
