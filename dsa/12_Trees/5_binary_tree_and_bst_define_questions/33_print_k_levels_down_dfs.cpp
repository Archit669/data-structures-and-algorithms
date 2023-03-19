#include<iostream>
#include<string.h>
#include<vector>
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

int idx = 0;
Node* constructTree(vector<int>& arr) {
  if (idx == arr.size() || arr[idx] == -1) {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}


void helper(Node* node, int level, int k){
    if (!node || level > k) return;
    if (level == k){
        cout << node->data << endl;
        return;
    }
    helper(node->left, level+1, k);
    helper(node->right, level+1, k);
}

void kLevelsDown(Node* node, int k) {
   helper(node, 0, k);
}

int main() {
  vector<int> arr;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string inp;
    cin >> inp;
    if (inp != "n") {
      arr.push_back(stoi(inp));
    }
    else {
      arr.push_back(-1);
    }
  }
  Node* root = constructTree(arr);
  int k;
  cin >> k;
  kLevelsDown(root, k);
  return 0;
}