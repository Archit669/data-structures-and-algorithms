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
    s += to_string(node->data) + " Child: ";
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

bool helper(Node *node, int data, vector<int> &ans)
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->data == data)
    {
        ans.push_back(data);

        return true;
    }

    for (auto &child : node->children)
    {
        bool res = helper(child, data, ans);

        if (res == true)
        {
            ans.push_back(node->data);

            return true;
        }
    }

    return false;
}

vector<int> nodeToRootPath(Node *node, int data)
{
    vector<int> path;

    helper(node, data, path);

    return path;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int data;
    cin >> data;

    Node *root = constructor01(arr);
    vector<int> ans = nodeToRootPath(root, data);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    solve();
    return 0;
}