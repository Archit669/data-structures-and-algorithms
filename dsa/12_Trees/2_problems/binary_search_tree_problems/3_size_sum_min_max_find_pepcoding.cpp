#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {

        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

int min(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node ? node->data : -1;
}

int max(Node *node)
{
    while (node && node->right)
        node = node->right;
    return node ? node->data : -1;
}

int sum(Node *node)
{
    return node ? sum(node->left) + sum(node->right) + node->data : 0;
}

int size(Node *node)
{
    return node ? 1 + size(node->left) + size(node->right) : 0;
}

bool find(Node *node, int data)
{
    if (!node)
        return false;

    if (node->data == data)
        return true;

    if (node->data > data)
        return find(node->left, data);
        
    else
        find(node->right, data);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(x);
        }
    }
    int data;
    cin >> data;
    Node *root = construct(arr);
    cout << size(root) << "\n"
         << sum(root) << "\n"
         << max(root) << "\n"
         << min(root) << "\n";
    if (find(root, data))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}