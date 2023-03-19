#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node*> children;



  Node(int data)

  {

    this->data = data;

  }

};

Node* constructor01(vector<int>& arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node*> stack;

  stack.push_back(new Node(arr[0]));



  Node* root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node* node = stack.back();

      Node* nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}

// using stack , queue and nullptr
void levelOderZigZag(Node* node)
{
  queue<Node*> que;
  que.push(node);
  que.push(nullptr);
  stack<int> stk;
  
  vector<int> ans;
  bool dir = 0;
  
  while (!que.empty()){
      Node* frontNode = que.front();
      que.pop();
      
      if (frontNode == nullptr){
          if (!que.empty()){
              que.push(nullptr);
          }
          
          if (dir == 1){
              while (!stk.empty()){
                  ans.push_back(stk.top());
                  stk.pop();
              }
          }
          
          dir = !dir;
          ans.push_back(-1);
      }else{
          if (dir == 0){
              ans.push_back(frontNode->data);
          }else{
              stk.push(frontNode->data);
          }
          
          for (auto &child : frontNode->children){
              que.push(child);
          }
      }
    }

    for (auto &x : ans){
        if (x == -1){
            cout << endl;
        }else{
            cout << x << " ";
        }
    }
}

void solve()
{
  int n;
  cin >> n;
  vector<int>arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = constructor01(arr);
  levelOderZigZag(root);
}

int main()
{
  solve();
  return 0;
}
