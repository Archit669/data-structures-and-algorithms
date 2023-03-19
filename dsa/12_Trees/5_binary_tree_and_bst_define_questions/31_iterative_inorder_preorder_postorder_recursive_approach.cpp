#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data) {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;
  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
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


// recursive approach
void helper(Node* root, vector<int> &pre, vector<int> &in , vector<int> &post){
    if (!root) return;
    pre.push_back(root->data);
    helper(root->left, pre, in, post);
    in.push_back(root->data);
    helper(root->right, pre, in , post);
    post.push_back(root->data);
}


void iterativePrePostInTraversal(Node* node) {
  vector<int> in, pre, post;
  helper(node, pre, in, post);
  for (auto &x : pre)  cout << x << " "; cout << endl;
  for (auto &x : in )  cout << x << " "; cout << endl;
  for (auto &x : post) cout << x << " "; cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(temp);
    }
  }
  Node* root = construct(arr);
  iterativePrePostInTraversal(root);
}