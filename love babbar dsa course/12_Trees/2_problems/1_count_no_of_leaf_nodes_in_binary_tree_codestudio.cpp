#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
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

int noOfLeafNodes(BinaryTreeNode<int> *root){
     if (root == NULL) return 0;
     if (root->left == NULL && root->right == NULL) return 1;
     int count = 0;
     count+= noOfLeafNodes(root->left);
     count+= noOfLeafNodes(root->right);
    
     return count;
}