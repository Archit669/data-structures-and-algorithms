#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


// creation of binary Tree
void buildTree(Node* &root){
    int data;
    cout << "enter data: ";
    cin >> data;

    if (data != -1){
        root = new Node(data);
        
        cout << "enter data for left child of " << root->data << endl;
        buildTree(root->left);

        cout << "enter data for right child of " << root->data << endl;
        buildTree(root->right);
    }
}

// inorder traversal
void inorderTraversal(Node* &root){
    if (root == NULL) return ;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// preorder traversal
void preorderTraversal(Node* &root){
    if (root == NULL) return ;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// postorder traversal
void postorderTraversal(Node* &root){
    if (root == NULL) return ;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// level order traversal
void levelorderTraversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// reverse levelorder traversal
void reverselevelorderTraversal(Node* &root){
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL){
            if (!q.empty()){
                q.push(NULL);
            }
        }else{
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    s.pop();
    while (!s.empty()){
        Node* temp = s.top();
        s.pop();
        if (temp == NULL){
            cout << endl;
        }else{
            cout << temp->data << " ";
        }
    }

}

// build tree using level order
void buildTreeLevelOrder(Node* &root){
    queue<Node* > q;
    int data;
    cout << "enter data: ";
    cin >> data;
    if (data != -1){
        root = new Node(data);
        q.push(root);
    }

    while (!q.empty()){
         Node* temp = q.front();
         q.pop();
         cout << "enter data for left child of " << temp->data<< endl;
         cin >> data;
         if (data != -1){
            temp->left = new Node(data);
            q.push(temp->left);
         }

         cout << "enter data for right child of " << temp->data << endl;
         cin >> data;
         if (data != -1){
            temp->right = new Node(data);
            q.push(temp->right);
         }
    }
}

int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    // buildTree(root);
    buildTreeLevelOrder(root);
    cout << "\n inorder traversal of binary Tree is \n";
    inorderTraversal(root);
    cout << "\n preorder traversal of binary Tree is \n";
    preorderTraversal(root);
    cout << "\n postorder traversal of binary Tree is \n";
    postorderTraversal(root);
    cout << "\n levelorder traversal of binary Tree is \n";
    levelorderTraversal(root);
    cout << "\n reverse levelorder traversal of binary Tree is \n";
    reverselevelorderTraversal(root);

    return 0;
}