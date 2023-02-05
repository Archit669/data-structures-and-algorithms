#include <bits/stdc++.h> 
using namespace std;

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
    if (!root) return true;
    bool ans = true;
    ans &= root->left ? (root->left->data <= root->data) ? true : false : true;
    ans &= root->right ? (root->right->data >= root->data) ? true : false : true;
    ans &= validateBST(root->left) && validateBST(root->right);
    return  ans;
}