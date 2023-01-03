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


/*
    // approach - 1 (double inorder traversal and use extra space )

    void inorder(BinaryTreeNode<int> *root, vector<BinaryTreeNode<int> *> &v){
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
    {
        vector<BinaryTreeNode<int> *> v;
        inorder(root,v);
        for (int i = 0 ; i<v.size()-1; i++){
            if (v[i] == node){
                return v[i+1];
            }
        }
        return NULL;
    }
    
*/


/*
    // approach - 2 (single inorder traversal)
    BinaryTreeNode<int> * inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, bool &flag){
        // base case
        if (root == NULL) return NULL;
        // find inorder successor from left subtree
        BinaryTreeNode<int> *ans = inorderSuccesor(root->left, node, flag);
        // if left subtree have no inorder successor of given node so return null otherwise give ans
        // if ans is not null then it is our inorder successor so return it
        if (ans != NULL) return ans;
        // if our flag is on it means our current node is inorder successor of give node
        if (flag) return root;
        // if current node is the given node then turn on flag which means next node is inorder succesor
        if (root == node) flag = !flag;
        // find inorder succesor from right subtree
        ans = inorderSuccesor(root->right, node,flag);
        // ans is null or not null so return our ans
        return ans;
    }

    BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node){
        bool flag = 0;
        return inorderSuccesor(root, node , flag);
    }

*/


// approch -3 (iterative approach)

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    bool flag = 0;
    stack<BinaryTreeNode<int> *> s;
    BinaryTreeNode<int> *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
 
        curr = s.top();
        s.pop();
         
        if (flag) return curr;
        if (curr == node) flag = !flag;
        
        curr = curr->right;
    } 
    
    return NULL;
}
