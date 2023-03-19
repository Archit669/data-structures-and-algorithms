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
  s += to_string(node->data) + " Child: ";
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

vector<int>* rootNodeToPath(Node* node, int data)
{

  if (node->data == data)
  {
    vector<int>* base = new vector<int>();
    base->push_back(data);
    return base;
  }

  vector<int>* ans = new vector<int>();
  for (Node* child : node->children)
  {
    vector<int>* recAns = rootNodeToPath(child, data);
    if (recAns->size() > 0)
    {
      recAns->push_back(node->data);
      return recAns;
    }
  }
  return ans;
}



int lca(Node* node, int data1, int data2)
{

    vector<int>* path1 = rootNodeToPath(node, data1);
    vector<int>* path2 = rootNodeToPath(node, data2);
    
    int m = path1->size() , n = path2->size();

    int ptr1 = m-1, ptr2 = n-1;

    while (ptr1 >=0 && ptr2 >= 0)
    {
        if ((*path1)[ptr1] != (*path2)[ptr2])
        {
            return (*path1)[ptr1+1];
        }

        ptr1-- ;  ptr2--;
    }
    
    return (*path1)[ptr1+1];
}

void solve()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < arr.size(); i++)
  {
    cin >> arr[i];
  }

  int data1;
  cin >> data1;
  int data2;
  cin >> data2;

  Node* root = constructor01(arr);
  int Lca = lca(root, data1, data2);
  cout << Lca << endl;
}

int main()
{
  solve();
  return 0;
}