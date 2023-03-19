#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void leftBoundary(TreeNode<int>* root, vector<int>& ans){
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    while(root){
        if (root->left != NULL || root->right != NULL) ans.push_back(root->data);
        if (root->left) root = root->left;
        else root = root->right;
    }
}

void leafNodes(TreeNode<int>* root, vector<int> &ans){
    if (root == NULL) return ;
    leafNodes(root->left, ans);
    if (root->left == NULL && root->right == NULL) ans.push_back(root->data);
    leafNodes(root->right, ans);
}

void reverseRightBoundary(TreeNode<int>*root, vector<int> &ans){
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    if (root->right)
        reverseRightBoundary(root->right, ans);
    else
        reverseRightBoundary(root->left, ans);
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if (root && (root->left || root->right)) ans.push_back(root->data);
    leftBoundary(root->left, ans);
    leafNodes(root, ans);
    reverseRightBoundary(root->right, ans);
    return ans;
}