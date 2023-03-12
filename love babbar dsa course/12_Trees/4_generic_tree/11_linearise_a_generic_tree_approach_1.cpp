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

// time complexity - O(n^2)
// space complexity - O(n)
Node* linearize(Node* node)
{
    // linearlise all the childs of root node and store it in temp
    vector<Node*> temp;
    
    for (auto &child : node->children)
    {
        temp.push_back(linearize(child));
    }
    
    // connect the leaf node of linearlised first child subtree to second subtree , second subtree to third subtree and so on...
    for (int idx = 0 ; idx < int(temp.size()-1); idx++)
    {
        Node* cNode = temp[idx];
        
        while (cNode->children.size() > 0)
        {
            cNode = cNode->children[0];
        }
        
        cNode->children.push_back(temp[idx+1]);
    }
    
    // pop out all the childs from the leaf node except the first one
    while (node->children.size() > 1)
    {
        node->children.pop_back();
    }
    
    // return node
    return node;
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
  display(root);

}

int main()
{
  solve();
  return 0;
}

/*
// pepcoding way
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Node

{

public:
    int data = 0;

    vector<Node *> children;

    Node(int data)

    {

        this->data = data;
    }
};

void display(Node *node)
{
    string s = "";
    s += to_string(node->data) + " -> ";
    for (Node *child : node->children)
    {
        s += to_string(child->data) + ", ";
    }

    cout << s << "." << endl;

    for (Node *child : node->children)
    {
        display(child);
    }
}

Node *constructor01(vector<int> &arr)

{

    if (arr.size() == 0)

        return NULL;

    vector<Node *> stack;

    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)

    {

        if (arr[i] != -1)

        {

            Node *node = stack.back();

            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);

            stack.push_back(nnode);
        }

        else

            stack.pop_back();
    }

    return root;
}

// function to get tail of linearise generic tree
Node* getTail(Node* node)
{
    while (node->children.size() == 1)
    {
        node = node->children.back();
    }
    
    return node;
}

// function to linearise generic tree
Node *linearize(Node *node)
{
    for (auto &child : node->children)
    {
        linearize(child);
    }
    
    while (node->children.size() > 1)
    {
        // take last child
        Node* lastChild = node->children.back();

        // remove last child
        node->children.pop_back();

        // take second last child
        Node* secondLastChild = node->children.back();
        
        // get tail of last child
        Node* tail = getTail(secondLastChild);

        // Now connect tail to last child
        tail->children.push_back(lastChild);
    }

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = constructor01(arr);

    linearize(root);
    display(root);
}

int main()
{
    solve();
    return 0;
}

*/