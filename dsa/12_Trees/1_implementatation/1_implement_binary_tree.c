#include <stdio.h>
#include <stdlib.h>

// create custom data type Node
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// create an constructor
Node* createNode(int data){
    Node* newNode = (Node *)(malloc(sizeof(Node)));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// build binary tree recursively
Node* buildTree(Node* root){
    int data;
    printf("enter data: ");
    scanf("%d",&data);

    if (data == -1) return NULL;

    root = createNode(data);

    printf("enter data for left child of %d\n",root->data);
    root->left = buildTree(root->left);

    printf("enter data for right child of %d\n",root->data);
    root->right = buildTree(root -> right);

    return root;
}




int main(){
    Node* root = NULL;
    root = buildTree(root);
    return 0;
}