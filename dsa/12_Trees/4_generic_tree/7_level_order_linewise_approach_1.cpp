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

void display(Node* node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node* child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node* child : node->children)
  {
    display(child);
  }
}

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

// approach -1 using main queue and child queue
Node* linearize(Node* node)
{
  // create a main queue and child queue
  queue<Node*> mq;
  queue<Node*> cq;
  
  // push root node in main queue
  mq.push(node);
  
  // levelorder traversal
  while (mq.size() > 0 || cq.size() > 0)
  {
      if (mq.size() > 0)
      {
          // take first node from queue
          Node* frontNode = mq.front();
          
          // remove first node from queue
          mq.pop();
          
          // print the frontNode 
          cout << frontNode->data << " ";
          
          // push all the child of it, in child queue
          for (auto &child : frontNode->children)
          {
              cq.push(child);
          }
      }
      else
      {
          // print new line character
          cout << endl;
          
          // move all the elements of child queue to main queue
          while (cq.size() > 0)
          {
              Node* frontNode = cq.front();
              
              cq.pop();
              
              mq.push(frontNode);
          }
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

  linearize(root);
//   display(root);

}

int main()
{
  solve();
  return 0;
}