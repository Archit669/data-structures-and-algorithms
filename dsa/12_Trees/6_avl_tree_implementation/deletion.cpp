#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};



Node *inorderSucc(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

// function to calculate height
int height(Node *root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

// function to get balance of given node
int getBalance(Node *root)
{
    if (root == nullptr)
        return 0;
    return height(root->left) - height(root->right);
}

// function for left Rotation
Node *leftRotate(Node *x)
{

    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// function for right Rotation
Node *rightRotate(Node *x)
{

    Node *y = x->left;
    Node *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else
    {
        // with one or no child
        if (root->left == nullptr || root->right == nullptr)
        {

            Node *temp = root->left ? root->left : root->right;

            // no child case
            if (temp == nullptr)
            {
                root = nullptr;
            }
            // one child case
            else
            {
                root = temp;
            }
        }

        // two child case
        else
        {

            Node *temp = inorderSucc(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // left right case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // right left case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}