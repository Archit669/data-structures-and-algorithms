#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  vector<Node*>children;
};

void iterativePreAndPostOrder(Node* root) {
  if (!root) return;
  
  string pre, post;
  
  stack<pair<Node*,int>> s;
  s.push({root, -1});
  
  while (!s.empty()){
      auto top = s.top();
      Node* node = top.first;
      int state = top.second;
      
      if (state == -1){
          // pre s++ 
          pre+= to_string(node->data) + " ";
          s.top().second++;
          
      }else if (state == node->children.size()){
          // post pop
          post+= to_string(node->data) + " ";
          s.pop();
          
      }else{
          // change state of parent so that next time new children will go
          s.top().second++;
          s.push({node->children[state], -1});
      }
  }
  
  cout << pre << endl;
  cout << post << endl;
  
  
}

Node* construct(vector<int>& arr) {
  Node* root = nullptr;

  stack <Node*> st;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = new Node();
      t->data = arr[i];

      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}

int main() {
  int n, x;
  cin >> n;
  vector<int>arr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  Node* root = construct(arr);
  iterativePreAndPostOrder(root);
}