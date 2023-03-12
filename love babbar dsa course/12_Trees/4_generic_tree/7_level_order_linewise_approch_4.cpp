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

// approch-4 levelorder using mq and pair
Node* linearize(Node* node)
{
    // create a main queue
    queue<pair<Node*, int>> mq;
    
    // push root node in main queue
    mq.push({node,0});
    
    int prevLevel = 0;
    
    // level order traversal
    while (!mq.empty())
    {
        // take node and level 
        Node* frontNode = mq.front().first;
        int currLevel = mq.front().second; 
        
        // pop element from queue
        mq.pop();
        
        // check if curr_level is equal to prev_level or not
        if (currLevel != prevLevel)
        {
            prevLevel = currLevel;
            
            cout << endl;
        }
        
        // print frontNode
        cout << frontNode->data << " ";
        
        // move all the child of frontNode to queue with level+1
        for (auto &child : frontNode->children)
        {
            mq.push({child, currLevel+1});
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

}

int main()
{
  solve();
  return 0;
}