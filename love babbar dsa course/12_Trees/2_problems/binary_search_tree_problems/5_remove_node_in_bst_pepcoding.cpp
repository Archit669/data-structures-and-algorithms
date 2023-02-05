#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}
void display(Node* node) {
  if (node == nullptr) {
    return;
  }

  string str = " <- " + to_string(node->data) + " -> ";

  string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
  string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

  str = left + str + right;
  cout << str << endl;

  display(node->left);
  display(node->right);
}



// ------------------------- main code  start ------------------------------------------------
int max(Node* root) {
  if (root->right == nullptr) {
    return root->data;
  }
  return max(root->right);
}


int min(Node* root) {
  if (root->left == nullptr) {
    return root->data;
  }
  return min(root->left);
}


Node* remove(Node* root, int data) {
    if (root == NULL) return root;
    // leaf nodes
    if (not root->left && not root->right && root->data == data){
        delete root;
        return NULL;
    }
    // for middle nodes
    if (root->data == data){
        if (root->left){
            root->data = max(root->left);
            root->left = remove(root->left, root->data);
        }else{
            root->data = min(root->right);
            root->right = remove(root->right, root->data);
        }
        return root;
    }
    // delete node from left subtree
    else if (root->data > data){
        root->left = remove(root->left, data);
    }else{
        root->right = remove(root->right, data);
    }

    return root;
}

// ------------------------------ main code end ----------------------------------------

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);

  root = remove(root, data);

  display(root);
}