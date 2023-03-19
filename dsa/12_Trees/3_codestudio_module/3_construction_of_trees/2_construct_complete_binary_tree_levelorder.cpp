#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};


TreeNode <int>* constructCBT(vector <int> arr)
{
    if (arr.size() == 0) return NULL;
    int i = 0;
    TreeNode <int>* root = new TreeNode <int>(arr[i++]);
    queue<TreeNode <int>*> q;
    q.push(root);
    
    while (!q.empty()){
        TreeNode <int>* temp = q.front();
        q.pop();
        
        if (i < arr.size()){
            temp->left = new TreeNode <int>(arr[i++]);
            q.push(temp->left);
        }
        
        if (i < arr.size()){
            temp->right = new TreeNode <int>(arr[i++]);
            q.push(temp->right);
        }  
    }
    
    return root;
}