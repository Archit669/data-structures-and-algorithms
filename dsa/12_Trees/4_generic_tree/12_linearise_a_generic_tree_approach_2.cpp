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


// function to linearise generic tree
Node *linearize(Node *node)
{
    // base case , if root node is leaf node
    if (node->children.size() == 0)
    {
        return node;
    }
    
    Node* lastChildTail = linearize(node->children.back());
    
    while (node->children.size() > 1)
    {
        // find the last child
        Node* lastChild = node->children.back();
        
        // remove the last child
        node->children.pop_back();
        
        // find the linearise second last child and find its tail    
        Node* secondLastChild = node->children.back();
        
        Node* secondLastChildTail = linearize(secondLastChild);
        
        // connect tail of second last child to last child
        secondLastChildTail->children.push_back(lastChild);
    }

    return lastChildTail;
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