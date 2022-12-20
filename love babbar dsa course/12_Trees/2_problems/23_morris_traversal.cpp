#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }

};

// build Tree from levelOrder
Node* buildTree(vector<int> &tree){
    Node* root = new Node(tree[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty()){
        Node* front = q.front();
        q.pop();

        if (i < tree.size() && tree[i] != -1){
            front->left = new Node(tree[i]);
            q.push(front->left);
            i++;
        }
        else {
            front->left = NULL;
            i++;
        }
 
        if (i < tree.size() && tree[i] != -1 ){
            front->right = new Node(tree[i]);
            q.push(front->right);
            i++;
        }
        else {
            front->right = NULL;
            i++;
        }
    }

    return root;
}


// print inorder traversal
void inorder(Node* root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


Node* findPredecessor(Node* curr){
    Node* temp = curr;
    curr = curr->left;
    while (curr->right && curr->right != temp){
        curr = curr->right;
    }

    return curr;
}

// morris traversal
void morrisTraversal(Node* root){
    Node* curr = root;
    while (curr != NULL){
        if (curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }else{
            Node* predecessor = findPredecessor(curr);
            if (predecessor->right == NULL){
                predecessor->right = curr;
                curr = curr->left;
            }else{
                predecessor->right = NULL;
                cout << curr->data << " ";
                curr= curr->right;
            }
        }
    }
}

int main(){
    vector<int> tree;
    while (true){
        int data;
        cin >> data;

        if (data == -2) break;
        else tree.push_back(data);
    }

    Node* root = buildTree(tree);
    inorder(root); cout << endl;
    morrisTraversal(root); cout << endl;

    

    return 0;
}