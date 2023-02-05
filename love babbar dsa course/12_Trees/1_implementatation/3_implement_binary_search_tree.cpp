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

void insertBST(Node* &root, int data){
    if (root == NULL){
        root = new Node(data);
    }else{
        if (root->data >= data){
            insertBST(root->left, data);
        }else{
            insertBST(root->right , data);
        }
    }
}

void inorder(Node* root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
        return;


    Node* root = NULL;

    for (auto &x : arr){
        insertBST(root, x);
    }

    inorder(root);


    return 0;

}