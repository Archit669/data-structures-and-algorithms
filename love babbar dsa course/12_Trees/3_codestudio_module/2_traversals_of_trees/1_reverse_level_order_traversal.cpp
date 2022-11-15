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

vector<int> reverseLevelOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        ans.push_back(temp->val);

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}