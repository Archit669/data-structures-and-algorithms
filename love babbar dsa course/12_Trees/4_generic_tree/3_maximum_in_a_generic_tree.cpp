#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}
void display(Node *node)
{
    string str = to_string(node->data) + "-> ";
    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str = str + ".";
    cout << str << endl;
    for (Node *child : node->children)
    {
        display(child);
    }
}

int maximum(Node *node)
{
    if (node == nullptr)
    {
        return INT_MIN;
    }

    int maxi = node->data;

    for (auto &child : node->children)
    {
        maxi = max(maximum(child), maxi);
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    int ans = maximum(root);
    cout << ans << endl;
    // display(root);
}