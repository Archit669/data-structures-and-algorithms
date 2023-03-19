#include <bits/stdc++.h>
using namespace std;

// create Node class for binary Tree
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


// create function to build binary Tree
void BuildTree(Node* &root){
    cout << "enter data: ";
    int data;
    cin >> data;

    if (data == -1){
        root = NULL;
    }else{
        root = new Node(data);
        cout << "enter data for left child of " << root->data << endl;
        BuildTree(root->left);
        cout << "enter data for right child of " << root->data << endl;
        BuildTree(root->right);
    }
}

// level order traversal
void levelOrderTraversal(Node* &root){
    queue<Node *> q;
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


// reverse level order traversal
void reverseLevelOrder(Node* root)
{
    stack<Node* > s;
    queue<Node* > q;

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
            if (temp->right)
                q.push(temp->right);

            if (temp->left)
                q.push(temp->left);
        }

    }

    while (!s.empty()){
        Node* temp = s.top();
        if (temp == NULL) cout << endl;
        else cout << temp->data << " ";
        s.pop();
    }cout << endl;
}


// inorder traversal
void inorderTraversal(Node* root){
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// preorder traversal
void preorderTraversal(Node* root){
    if (root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// postorder traversal
void postorderTraversal(Node* root){
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


// build tree from level order traversal
void buildTreeFromLevelOrder(Node* &root){
    queue<Node *> q;
    int data;
    cout << "enter data: ";
    cin >> data;
    if (data != -1){
        root= new Node(data);
        q.push(root);
    }

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        int data;
        cout << "enter data for left of " << temp->data << endl;
        cin >> data;
        if (data != -1){
           temp->left = new Node(data);
           q.push(temp->left);
        }

        cout << "enter data for right of " << temp->data << endl;
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
    // BuildTree(root);
    buildTreeFromLevelOrder(root);
    cout << endl;

    cout << "\n level order traversal is \n";
    levelOrderTraversal(root);
    cout << "\n reverse level order traversal is \n";
    reverseLevelOrder(root);
    cout << "\n inorder traversal is \n";
    inorderTraversal(root);
    cout << "\n preorder traversal is \n";
    preorderTraversal(root);
    cout << "\n postorder traversal is \n";
    postorderTraversal(root);
    cout << endl;
    return 0;
}