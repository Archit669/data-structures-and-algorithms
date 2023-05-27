//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};


class Solution{
    
    // function to calculate height 
    int height(Node* root){
        if (root == nullptr) return 0;
        return root->height;
    }
    
    // function to get balance of given node
    int getBalance(Node* root){
        if (root == nullptr) return 0;
        return height(root->left) - height(root->right);
    }
    
    // function for left Rotation
    Node* leftRotate(Node* x){
        
        Node* y = x -> right;
        Node* t2 = y -> left;
        
        y->left = x;
        x->right = t2;
        
        x->height = 1 + max(height(x->left) , height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        
        return y;
    }
    
    // function for right Rotation
    Node* rightRotate(Node* x){
        
        Node* y = x->left;
        Node* t2 = y -> right;
        
        y->right = x;
        x->left = t2;
        
        x->height = 1 + max(height(x->left) , height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        
        return y;
    }
    
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* root, int data)
    {  
        // tree is empty
        if (!root) return new Node(data);
        
        // upcoming valued is greater than than the value of root
        else if (root->data < data){
            root->right = insertToAVL(root->right, data);
        }
        
        // upcoming value is less than the value of root
        else if (root->data > data){
            root->left = insertToAVL(root->left, data);
        }
        
        else{
            return root;
        }
        
        // update the height of curr node
        root->height = 1 + max(height(root->left), height(root->right));
        
        // calulate the balance factor
        int balance = getBalance(root);
        
        // cases for rotations
        
        // LL Rotation
        if (balance > 1 && data < root->left->data){
            return rightRotate(root);
        }
        
        // RR Rotation
        if (balance < -1 && data > root->right->data){
            return leftRotate(root);
        }
        
        // LR Rotation
        if (balance > 1 && data > root->left->data){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        // RL Rotation
        if (balance < -1 && data < root->right->data){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }
};

