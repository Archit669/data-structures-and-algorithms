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

// approch-3 levelorder using mq and size variable 
Node* linearize(Node* node)
{
    // create a main queue
    queue<Node*> mq;
    
    // push root node in main queue
    mq.push(node);
    
    // level order traversal
    while (!mq.empty())
    {
        // calculate size of main queue
        int size = mq.size();
        
        // print all the elements at current level and push child of each node at that level
        for (int idx = 0 ; idx < size ; idx++)
        {
            Node* frontNode = mq.front();
            
            mq.pop();
            
            cout << frontNode->data << " ";
            
            for (auto &child : frontNode->children)
            {
                mq.push(child);
            }
        }
        
        // newline character as one level is over
        cout << endl;
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

}

int main()
{
  solve();
  return 0;
}